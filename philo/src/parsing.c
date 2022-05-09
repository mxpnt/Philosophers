/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapontil <mapontil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 18:32:30 by maxime            #+#    #+#             */
/*   Updated: 2022/05/09 11:06:10 by mapontil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

static int	data_init(int i, char **arg, t_data *data)
{
	if (is_valid(arg[i]) || is_not_limit(arg[i]) || is_not_number(arg[i]))
		return (error("not valid argument"));
	if (i == 1)
		data->nb = ft_atolli(arg[i]);
	else if (i == 2)
		data->time_to_die = ft_atolli(arg[i]);
	else if (i == 3)
		data->time_to_eat = ft_atolli(arg[i]);
	else if (i == 4)
		data->time_to_sleep = ft_atolli(arg[i]);
	else if (i == 5)
		data->must_eat = ft_atolli(arg[i]);
	return (0);
}

static int	data_philo_init(t_data *data)
{
	data->philo = malloc(data->nb * sizeof(t_philo));
	if (!data->philo)
		return (error("malloc"));
	data->fork_mutex = malloc(data->nb * sizeof(pthread_mutex_t));
	if (!data->fork_mutex)
		return (error("malloc"));
	return (0);
}

static void	philo_init(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->nb)
	{
		data->philo[i].ate = 0;
		data->philo[i].left_fork_id = i;
		data->philo[i].right_fork_id = (i + 1) % data->nb;
		data->philo[i].id = i;
		data->philo[i].data = data;
	}
}

int	parsing_arg(int argc, char **argv, t_data *data)
{
	int	i;

	i = 0;
	while (++i < argc)
		if (data_init(i, argv, data) != 0)
			return (1);
	data_philo_init(data);
	philo_init(data);
	return (0);
}
