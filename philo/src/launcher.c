/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launcher.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapontil <mapontil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 09:51:09 by mapontil          #+#    #+#             */
/*   Updated: 2022/05/03 12:59:24 by mapontil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	*routine(void *info)
{
	t_philo	*philo;
	t_data	*data;

	philo = (t_philo *)info;
	data = philo->data;
	gettimeofday(&data->time, NULL);
	pthread_mutex_lock(&data->left_fork_mutex);
	printf("%ld: %d has taken a fork %d\n", data->time.tv_sec, philo->id, philo->left_fork_id);
	pthread_mutex_lock(&data->right_fork_mutex);
	printf("%ld: %d has taken a fork %d\n", data->time.tv_sec, philo->id, philo->right_fork_id);
	pthread_mutex_lock(&data->eat_mutex);
	printf("%ld: %d is eating\n", data->time.tv_sec, philo->id);
	pthread_mutex_unlock(&data->eat_mutex);
	pthread_mutex_unlock(&data->left_fork_mutex);
	pthread_mutex_unlock(&data->right_fork_mutex);
	return (0);
}

static void	destroy_mutex(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->nb)
		pthread_mutex_destroy(&data->process_mutex[i]);
	pthread_mutex_destroy(&data->left_fork_mutex);
	pthread_mutex_destroy(&data->right_fork_mutex);
}

int	launcher(t_data *data)
{
	int				i;

	gettimeofday(&data->time, NULL);
	pthread_mutex_init(&data->left_fork_mutex, NULL);
	pthread_mutex_init(&data->right_fork_mutex, NULL);
	pthread_mutex_init(&data->eat_mutex, NULL);
	i = -1;
	while (++i < data->nb)
	{
		pthread_mutex_init(&data->process_mutex[i], NULL);
		if (pthread_create(&data->philo_id[i], NULL, &routine, (void *)&data->philo[i]) != 0)
			return (error("pthread_create"));
	}
	i = -1;
	while (++i < data->nb)
	{
		if (pthread_join(data->philo_id[i], NULL) != 0)
			return (error("pthread_join"));
	}
	destroy_mutex(data);
	// fonction destroy mutex;
	return (0);
}
