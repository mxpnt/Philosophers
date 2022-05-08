/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxime <maxime@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 18:14:09 by maxime            #+#    #+#             */
/*   Updated: 2022/05/08 19:23:25 by maxime           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	main(int argc, char **argv)
{
	t_data	data;
	// int		i;
	
	// i = 0;
	if (argc == 5 || argc == 6)
	{
		init_data(&data);
		parsing_arg(argc, argv, &data);
		// retour ./philo 1 0 0 0
		// error quand argc6 == 0
		launcher(&data);
		free_all(&data);
	}
	else
		error("Wrong number of argument");
	return (0);
}
