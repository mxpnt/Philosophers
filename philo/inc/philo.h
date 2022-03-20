/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxime <maxime@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 18:13:20 by maxime            #+#    #+#             */
/*   Updated: 2022/03/20 19:17:01 by maxime           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include "stdlib.h"
#include "limits.h"

typedef struct s_data
{
    int nb;
    int time_to_die;
    int time_to_eat;
    int time_to_sleep;
    int must_eat;
}   t_data;


#endif