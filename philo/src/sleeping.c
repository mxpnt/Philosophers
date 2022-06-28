/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleeping.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapontil <mapontil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 12:45:36 by mapontil          #+#    #+#             */
/*   Updated: 2022/05/11 09:09:39 by mapontil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	sleeping(t_data *data, int time)
{
	long long	init_time;

	init_time = gettime(data);
	while (1)
	{
		if ((gettime(data) - init_time) >= time)
			break ;
		usleep(50);
	}
}
