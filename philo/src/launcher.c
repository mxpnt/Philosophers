/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launcher.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxime <maxime@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 09:51:09 by mapontil          #+#    #+#             */
/*   Updated: 2022/05/03 21:22:03 by maxime           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	eat(t_philo *philo)
{
	t_data	*data;

	data = philo->data;
	pthread_mutex_lock(&data->fork_mutex[philo->left_fork_id]);
	pthread_mutex_lock(&data->fork_mutex[philo->right_fork_id]);
	printf("%lld: %d has taken a fork\n", gettime(), philo->id);
	pthread_mutex_lock(&data->eat_mutex);
	printf("%lld: %d is eating\n", gettime(), philo->id);
	philo->last_meal = gettime();
	pthread_mutex_unlock(&data->eat_mutex);
	philo->ate += 1;
	pthread_mutex_unlock(&data->fork_mutex[philo->left_fork_id]);
	pthread_mutex_unlock(&data->fork_mutex[philo->right_fork_id]);
}

void	*routine(void *info)
{
	t_philo	*philo;
	t_data	*data;

	philo = (t_philo *)info;
	data = philo->data;
	while (data->deadge == 0)
	{
		eat(philo);
		philo_sleep(data, philo->id);
		sleeping(data);
		philo_think(data, philo->id);
	}
	return (NULL);
}

// static void	check_death(t_philo *philo)
// {

// }

static void	destroy_mutex(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->nb)
		pthread_mutex_destroy(&data->fork_mutex[i]);
	pthread_mutex_destroy(&data->eat_mutex);
	pthread_mutex_destroy(&data->action_mutex);
}

int	launcher(t_data *data)
{
	int		i;

	pthread_mutex_init(&data->eat_mutex, NULL);
	pthread_mutex_init(&data->action_mutex, NULL);
	i = -1;
	while (++i < data->nb)
	{
		if (pthread_create(&data->philo[i].philo_id, NULL, &routine, (void *)&data->philo[i]) != 0)
			return (error("pthread_create"));
	}
	check_death();
	i = -1;
	while (++i < data->nb)
	{
		if (pthread_join(data->philo[i].philo_id, NULL) != 0)
			return (error("pthread_join"));
	}
	destroy_mutex(data);
	return (0);
}
