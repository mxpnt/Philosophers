/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapontil <mapontil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 18:23:08 by maxime            #+#    #+#             */
/*   Updated: 2022/05/11 11:49:25 by mapontil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	init_data(t_data *data)
{
	data->nb = 0;
	data->time_to_die = 0;
	data->time_to_eat = 0;
	data->time_to_sleep = 0;
	data->must_eat = -1;
	data->deadge = 0;
	data->all_ate = 0;
}

void	init_mutex(t_data *data)
{
	int		i;

	i = 0;
	while (i < data->nb)
	{
		pthread_mutex_init(&(data->fork_mutex[i]), NULL);
		i++;
	}
	pthread_mutex_init(&(data->deadge_mutex), NULL);
	pthread_mutex_init(&(data->eat_mutex), NULL);
	pthread_mutex_init(&(data->action_mutex), NULL);
	pthread_mutex_init(&(data->time_mutex), NULL);
}
