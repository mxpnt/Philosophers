/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapontil <mapontil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 18:14:09 by maxime            #+#    #+#             */
/*   Updated: 2022/05/03 08:26:24 by mapontil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc == 5 || argc == 6)
	{
		init_data(&data);
		parsing_arg(argc, argv, &data);
		// fonction error a peaufiner
		// fonction free philo tab int
	}
	else
		write(2, "Error: Wrong number of argument\n", 32);
	return (0);
}
