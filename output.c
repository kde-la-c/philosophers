/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kde-la-c <kde-la-c@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 21:06:28 by kde-la-c          #+#    #+#             */
/*   Updated: 2023/10/14 21:06:31 by kde-la-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_tstamp(long stsec, long stusec)
{
	struct timeval	tv;
	unsigned int	tstamp;
	(void)stusec;
	(void)stsec;

	gettimeofday(&tv, NULL);
	tstamp = ((tv.tv_sec - stsec) * 1000) + ((tv.tv_usec - stusec) / 1000);
	printf(">%i\n", tstamp);
}
