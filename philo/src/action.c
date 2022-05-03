/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxime <maxime@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 20:47:11 by maxime            #+#    #+#             */
/*   Updated: 2022/05/03 21:16:47 by maxime           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	philo_sleep(t_data *data, int id)
{
	pthread_mutex_lock(&data->action_mutex);
	if (data->deadge == 0)
		printf("%lld: %d is sleeping\n", gettime(), id);
	pthread_mutex_lock(&data->action_mutex);
}

void	sleeping(t_data *data)
{
	long long	time;
	int			wakeup;

	time = gettime();
	wakeup = 0;
	while (data->deadge == 0 && wakeup == 0)
	{
		if ((gettime() - time) >= time)
			wakeup = 1;
	}
}

void	philo_think(t_data *data, int id)
{
	pthread_mutex_lock(&data->action_mutex);
	if (data->deadge == 0)
		printf("%lld: %d is thinking\n", gettime(), id);
	pthread_mutex_lock(&data->action_mutex);
}
