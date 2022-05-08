/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxime <maxime@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 19:31:13 by maxime            #+#    #+#             */
/*   Updated: 2022/05/07 16:27:19 by maxime           ###   ########.fr       */
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
