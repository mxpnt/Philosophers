/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapontil <mapontil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 18:13:20 by maxime            #+#    #+#             */
/*   Updated: 2022/05/03 12:13:03 by mapontil         ###   ########.fr       */
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

struct	s_philo;

typedef struct s_philo
{
	int				id;
	int				left_fork_id;
	int				right_fork_id;
	struct timeval	last_meal;
	struct s_data	*data;
}	t_philo;

typedef struct s_data
{
	int				nb;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat;
	struct timeval	time;
	pthread_t		*philo_id;
	pthread_mutex_t	*process_mutex;
	pthread_mutex_t	left_fork_mutex;
	pthread_mutex_t	right_fork_mutex;
	pthread_mutex_t	eat_mutex;
	t_philo			*philo;
}	t_data;

// error.c
int				error(char *str);

// free.c
void			free_all(t_data *data);

// init.c
void			init_data(t_data *data);

// launcher.c
int				launcher(t_data *data);

// parsing.c
void			parsing_arg(int argc, char **argv, t_data *data);

// utils.c
int				is_valid(char *str);
int				is_not_number(char *str);
int				is_not_limit(char *str);
long long int	ft_atolli(char *str);
void			ft_putstr_fd(char *s, int fd);

#endif