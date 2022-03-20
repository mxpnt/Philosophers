/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxime <maxime@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 19:03:16 by maxime            #+#    #+#             */
/*   Updated: 2022/03/20 19:18:21 by maxime           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int is_not_number(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (!(str[i] >= '0' && str[i] <= '9'))
            return (1);
        i++;
    }
    return (0);
}

int is_not_limit(char *str)
{
    if (ft_atolli(str) < INT_MIN || ft_atolli(str) > INT_MAX)
        return (1);
    return (0);
}

long long int ft_atolli(char *str)
{
    int         i;
    long long int    neg;
    long long int    res;

    i = 0;
    neg = 1;
    res = 0;
    while (str[i] == '-' || str[i] == '+')
    {
        if (str[i] == '-')
            neg *= -1;
        i++''
    }
    while (str[i] >= '0' && str[i] <= '9')
    {
        res = res * 10 + (str[i] - 48);
        i++;
    }
    return (res * neg);
}
