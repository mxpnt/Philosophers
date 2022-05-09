/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapontil <mapontil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 20:47:11 by maxime            #+#    #+#             */
/*   Updated: 2022/05/09 12:45:24 by mapontil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	philo_fork(t_data *data, int id)
{	
	pthread_mutex_lock(&(data->action_mutex));
	if (data->deadge == 0)
		printf("%lld: %d has taken fork\n", \
		(gettime(data) - data->first_time), id + 1);
	pthread_mutex_unlock(&(data->action_mutex));
}

void	philo_eat(t_data *data, int id)
{
	pthread_mutex_lock(&(data->action_mutex));
	if (data->deadge == 0)
		printf("%lld: %d is eating\n", \
		(gettime(data) - data->first_time), id + 1);
	pthread_mutex_unlock(&(data->action_mutex));
}

void	philo_sleep(t_data *data, int id)
{
	pthread_mutex_lock(&(data->action_mutex));
	if (data->deadge == 0)
		printf("%lld: %d is sleeping\n", \
		(gettime(data) - data->first_time), id + 1);
	pthread_mutex_unlock(&(data->action_mutex));
}

void	philo_think(t_data *data, int id)
{
	pthread_mutex_lock(&(data->action_mutex));
	if (data->deadge == 0)
		printf("%lld: %d is thinking\n", \
		(gettime(data) - data->first_time), id + 1);
	pthread_mutex_unlock(&(data->action_mutex));
}

void	philo_die(t_data *data, int id)
{
	pthread_mutex_lock(&(data->action_mutex));
	if (data->deadge == 0)
		printf("%lld: %d died\n", \
		(gettime(data) - data->first_time), id + 1);
	pthread_mutex_unlock(&(data->action_mutex));
}
