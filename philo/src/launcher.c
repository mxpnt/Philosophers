/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launcher.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapontil <mapontil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 09:51:09 by mapontil          #+#    #+#             */
/*   Updated: 2022/05/11 13:33:31 by mapontil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

static void	lonely_philo(t_data *data)
{
	printf("0: 1 has taken fork\n");
	usleep(data->time_to_die * 1000);
}

void	eat(t_philo *philo)
{
	t_data	*data;

	data = philo->data;
	if (data->nb == 1)
	{
		lonely_philo(data);
		return ;
	}
	pthread_mutex_lock(&(data->deadge_mutex));
	if (data->deadge == 0)
	{
		pthread_mutex_unlock(&(data->deadge_mutex));
		pthread_mutex_lock(&(data->fork_mutex[philo->left_fork_id]));
		pthread_mutex_lock(&(data->fork_mutex[philo->right_fork_id]));
		philo_fork(data, philo->id);
		pthread_mutex_lock(&(data->eat_mutex));
		philo_eat(data, philo->id);
		philo->last_meal = gettime(data);
		pthread_mutex_unlock(&(data->eat_mutex));
		sleeping(data, data->time_to_eat);
		(philo->ate)++;
		pthread_mutex_unlock(&(data->fork_mutex[philo->left_fork_id]));
		pthread_mutex_unlock(&(data->fork_mutex[philo->right_fork_id]));
	}
}

void	*routine(void *info)
{
	t_philo	*philo;
	t_data	*data;

	philo = (t_philo *)info;
	data = philo->data;
	if (philo->id % 2)
		usleep(15000);
	pthread_mutex_lock(&(data->deadge_mutex));
	while (data->deadge == 0)
	{
		pthread_mutex_unlock(&(data->deadge_mutex));
		eat(philo);
		if (data->all_ate == 1)
			break ;
		philo_sleep(data, philo->id);
		sleeping(data, data->time_to_sleep);
		philo_think(data, philo->id);
		pthread_mutex_lock(&(data->deadge_mutex));
	}
	pthread_mutex_unlock(&(data->deadge_mutex));
	return (NULL);
}

static void	check_death(t_data *data, t_philo *philo)
{
	int	i;

	while (data->all_ate == 0)
	{
		i = -1;
		pthread_mutex_lock(&(data->deadge_mutex));
		while (++i < data->nb && data->deadge == 0)
		{
			pthread_mutex_unlock(&(data->deadge_mutex));
			pthread_mutex_lock(&(data->eat_mutex));
			if ((gettime(data) - philo[i].last_meal) > data->time_to_die)
				deadge(data, i);
			pthread_mutex_unlock(&(data->eat_mutex));
			usleep(100);
			pthread_mutex_lock(&(data->deadge_mutex));
		}
		if (check_deadge(data) == 1)
			return ;
		pthread_mutex_unlock(&(data->deadge_mutex));
		all_eat(data, philo);
	}
}

int	launcher(t_data *data)
{
	int		i;

	init_mutex(data);
	i = 0;
	data->first_time = gettime(data);
	while (i < data->nb)
	{
		data->philo[i].last_meal = gettime(data);
		if (pthread_create(&(data->philo[i].philo_id), NULL, \
		routine, &(data->philo[i])) != 0)
			return (error("pthread_create"));
		i++;
	}
	check_death(data, data->philo);
	i = data->nb - 1;
	while (i >= 0)
	{
		if (pthread_join(data->philo[i].philo_id, NULL) != 0)
			return (error("pthread_join"));
		i--;
	}
	destroy_mutex(data);
	return (0);
}
