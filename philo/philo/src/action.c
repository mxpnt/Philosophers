/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxime <maxime@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 20:47:11 by maxime            #+#    #+#             */
/*   Updated: 2022/05/05 20:45:03 by maxime           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	philo_eat(t_data *data, int id)
{
	pthread_mutex_lock(&(data->action_mutex));
	if (data->deadge == 0)
		printf("%ld: %d is eating\n", (gettime(data) - data->first_time), id);
	pthread_mutex_unlock(&(data->action_mutex));	
}

void	philo_sleep(t_data *data, int id)
{
	pthread_mutex_lock(&(data->action_mutex));
	if (data->deadge == 0)
		printf("%ld: %d is sleeping\n", (gettime(data) - data->first_time), id);
	pthread_mutex_unlock(&(data->action_mutex));
}

void	sleeping(t_data *data, int time)
{
	int			wakeup;

	wakeup = 0;
	while (data->deadge == 0 && wakeup == 0)
	{
		if ((gettime(data) - data->first_time) >= time)
			wakeup = 1;
		usleep(50);
	}
}

void	philo_think(t_data *data, int id)
{
	pthread_mutex_lock(&(data->action_mutex));
	if (data->deadge == 0)
		printf("%ld: %d is thinking\n", (gettime(data) - data->first_time), id);
	pthread_mutex_unlock(&(data->action_mutex));
}

void	philo_die(t_data *data, int id)
{
	pthread_mutex_lock(&(data->action_mutex));
	if (data->deadge == 0)
		printf("%ld: %d died\n", (gettime(data) - data->first_time), id);
	pthread_mutex_unlock(&(data->action_mutex));
}
