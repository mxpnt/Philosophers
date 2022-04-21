/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapontil <mapontil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 18:32:30 by maxime            #+#    #+#             */
/*   Updated: 2022/04/19 10:59:49 by mapontil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

static int	arg_init(int i, char **arg, t_data *data)
{
	if (i == 1)
		if (is_not_zero(arg[i]))
			return (1);
	if (is_not_number(arg[i]))
		return (2);
	if (is_not_limit(arg[i]))
		return (3);
	if (i == 0)
		data->nb = ft_atolli(arg[i]);
	else if (i == 1)
		data->time_to_die = ft_atolli(arg[i]);
	else if (i == 2)
		data->time_to_eat = ft_atolli(arg[i]);
	else if (i == 3)
		data->time_to_sleep = ft_atolli(arg[i]);
	else if (i == 4)
		data->must_eat = ft_atolli(arg[i]);
	return (0);
}

int	parsing_arg(int argc, char **argv, t_data *data)
{
	int	i;

	i = 0;
	while (++i < argc)
	{
		if (arg_init(i, argv, data) != 0)
			return (1);
	}
	return (0);
}
