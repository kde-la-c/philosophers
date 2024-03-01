/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kde-la-c <kde-la-c@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 18:59:32 by kde-la-c          #+#    #+#             */
/*   Updated: 2023/10/05 18:59:33 by kde-la-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	get_tstamp(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

void	ft_msleep(int sleeptime)
{
	int				orig_time;
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	orig_time = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	while (get_tstamp() < orig_time + sleeptime)
		usleep(50);
}
