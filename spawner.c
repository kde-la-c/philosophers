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

int towrite = 0;

void	*routine(void *mutex)
{
	pthread_mutex_t	lock;

	lock = *(pthread_mutex_t *)mutex;
	for (int i = 0; i < 1000000; i++)
	{
		pthread_mutex_lock(&lock);
		towrite++;
		pthread_mutex_unlock(&lock);
	}
	return (NULL);
}

int	spawn(pthread_mutex_t mutex)
{
	pthread_t	tid;

	if (pthread_create(&tid, NULL, routine, &mutex))
		return (1);
	if (pthread_join(tid, NULL))
		return (2);
	return (0);
}

int	spawner(int *args)
{
	int				i = 0;
	pthread_mutex_t	mutex;

	pthread_mutex_init(&mutex, NULL);
	while (i++ < args[0])
	{
		if (spawn(mutex))
			return (1);
	}
	pthread_mutex_destroy(&mutex);
	printf("towrite = %i\n", towrite);
	return (0);
}
