/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleeping.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapontil <mapontil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 12:45:36 by mapontil          #+#    #+#             */
/*   Updated: 2022/05/09 12:45:49 by mapontil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	sleeping(t_data *data, int time)
{
	long long	init_time;
	int			wakeup;

	init_time = gettime(data);
	wakeup = 0;
	while (data->deadge == 0 && wakeup == 0)
	{
		if ((gettime(data) - init_time) >= time)
			wakeup = 1 ;
		usleep(50);
	}
}
