/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxime <maxime@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 18:23:08 by maxime            #+#    #+#             */
/*   Updated: 2022/03/20 18:31:38 by maxime           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void    init_data(t_data *data)
{
    data->nb = 0;
    data->time_to_die = 0;
    data->time_to_eat = 0;
    data->time_to_sleep = 0;
    data->must_eat = 0;
}
