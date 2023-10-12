/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spawner.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kde-la-c <kde-la-c@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 23:21:53 by kde-la-c          #+#    #+#             */
/*   Updated: 2023/10/09 23:21:55 by kde-la-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *cutlery)
{
	(void)cutlery;
	printf("hey\n");
	return (NULL);
}

int	spawn(pthread_t tid, pthread_mutex_t *cutlery)
{
	if (pthread_create(&tid, NULL, routine, cutlery))
		return (1);
	if (pthread_join(tid, NULL))
		return (2);
	return (0);
}

int	spawner(int *args)
{
	int				i;
	pthread_t		*tids;
	pthread_mutex_t	*cutlery;
	(void)args;

	i = 0;
	tids = (pthread_t *)malloc(sizeof(pthread_t) * args[0]);
	cutlery = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * args[0]);
	while (i < args[0])
	{
		pthread_mutex_init(&(cutlery[i]), NULL);
		spawn(tids[i], cutlery);
		i++;
	}
	free(tids);
	free(cutlery);
	return (0);
}
