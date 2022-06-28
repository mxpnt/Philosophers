/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapontil <mapontil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 19:31:13 by maxime            #+#    #+#             */
/*   Updated: 2022/05/11 12:57:37 by mapontil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

long long	gettime(t_data *data)
{
	struct timeval	time;
	long long		timer;

	pthread_mutex_lock(&(data->time_mutex));
	gettimeofday(&time, NULL);
	timer = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	pthread_mutex_unlock(&(data->time_mutex));
	return (timer);
}

void	destroy_mutex(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->nb)
		pthread_mutex_destroy(&(data->fork_mutex[i]));
	pthread_mutex_destroy(&(data->deadge_mutex));
	pthread_mutex_destroy(&(data->eat_mutex));
	pthread_mutex_destroy(&(data->action_mutex));
	pthread_mutex_destroy(&(data->time_mutex));
}

int	check_deadge(t_data *data)
{
	if (data->deadge == 1)
	{
		pthread_mutex_unlock(&(data->deadge_mutex));
		return (1);
	}
	return (0);
}

void	deadge(t_data *data, int i)
{
	philo_die(data, data->philo[i].id);
	pthread_mutex_lock(&(data->deadge_mutex));
	data->deadge = 1;
	pthread_mutex_unlock(&(data->deadge_mutex));
}

void	all_eat(t_data *data, t_philo *philo)
{
	int	i;

	i = 0;
	while (data->must_eat != -1 && i < data->nb \
		&& philo[i].ate >= data->must_eat)
		i++;
	if (i == data->nb)
		data->all_ate = 1;
}
