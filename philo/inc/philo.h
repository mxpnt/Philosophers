/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapontil <mapontil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 18:13:20 by maxime            #+#    #+#             */
/*   Updated: 2022/05/09 12:48:35 by mapontil         ###   ########.fr       */
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
	int				ate;
	int				left_fork_id;
	int				right_fork_id;
	long			last_meal;
	pthread_t		philo_id;
	struct s_data	*data;
}	t_philo;

typedef struct s_data
{
	int				nb;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat;
	int				deadge;
	int				all_ate;
	long long		first_time;
	pthread_mutex_t	eat_mutex;
	pthread_mutex_t	action_mutex;
	pthread_mutex_t	time_mutex;
	pthread_mutex_t	*fork_mutex;
	t_philo			*philo;
}	t_data;

// action.c
void			philo_fork(t_data *data, int id);
void			philo_eat(t_data *data, int id);
void			philo_sleep(t_data *data, int id);
void			philo_think(t_data *data, int id);
void			philo_die(t_data *data, int id);

// error.c
int				error(char *str);

// free.c
void			free_all(t_data *data);

// init.c
void			init_data(t_data *data);
void			init_mutex(t_data *data);

// launcher.c
int				launcher(t_data *data);

// parsing.c
int				parsing_arg(int argc, char **argv, t_data *data);

// sleeping.c
void			sleeping(t_data *data, int time);

// utils.c
int				is_valid(char *str);
int				is_not_number(char *str);
int				is_not_limit(char *str);
long long		ft_atolli(char *str);
void			ft_putstr_fd(char *s, int fd);

// utils2.c
long long		gettime(t_data *data);

#endif