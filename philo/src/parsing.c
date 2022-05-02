/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxime <maxime@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 18:32:30 by maxime            #+#    #+#             */
/*   Updated: 2022/05/02 21:58:38 by maxime           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

static int	data_init(int i, char **arg, t_data *data)
{
	if (i == 1)
		if (is_not_zero(arg[i]))
			return (1);
	if (is_not_number(arg[i]))
		return (2);
	if (is_not_limit(arg[i]))
		return (3);
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
		return (1);
	return (0);
}

static void	philo_init(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->nb)
	{
		data->philo[i].id = i;
		data->philo[i].left_fork_id = i;
		data->philo[i].right_fork_id = (i + 1) % data->nb;
		data->philo[i].data = data;
	}
}

int	parsing_arg(int argc, char **argv, t_data *data)
{
	int	i;

	i = 0;
	while (++i < argc)
	{
		if (data_init(i, argv, data) != 0)
			return (1);
	}
	if (data_philo_init(data) != 0)
		return (1);
	philo_init(data);
	i = 0;
	while (i < data->nb)
	{
		dprintf(1, "%d = %d - %d - %d\n", i, data->philo[i].id, data->philo[i].left_fork_id, data->philo[i].right_fork_id);
		i++;
	}
	dprintf(1, "ok");
	return (0);
}
