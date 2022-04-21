/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapontil <mapontil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 18:13:20 by maxime            #+#    #+#             */
/*   Updated: 2022/04/19 10:58:57 by mapontil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "unistd.h"
# include "stdio.h"
# include "stdlib.h"
# include "sys/time.h"
# include "pthread.h"
# include "limits.h"

typedef struct s_data
{
	int	nb;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	must_eat;
}	t_data;

// error.c
int				error(int code);

// init.c
void			init_data(t_data *data);

// parsing.c
int				parsing_arg(int argc, char **argv, t_data *data);

// utils.c
int				is_not_zero(char *str);
int				is_not_number(char *str);
int				is_not_limit(char *str);
long long int	ft_atolli(char *str);

#endif