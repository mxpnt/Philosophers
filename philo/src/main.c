/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxime <maxime@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 18:14:09 by maxime            #+#    #+#             */
/*   Updated: 2022/05/02 20:04:17 by maxime           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc == 5 || argc == 6)
	{
		init_data(&data);
		if (parsing_arg(argc, argv, &data) != 0)
			return (error(1));
		// fonction error a peaufiner
		// fonction free philo tab int
	}
	else
		write(2, "Error: Wrong number of argument\n", 32);
	return (0);
}
