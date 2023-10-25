/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spawner.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kde-la-c <kde-la-c@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 22:10:12 by kde-la-c          #+#    #+#             */
/*   Updated: 2023/10/24 22:10:16 by kde-la-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

typedef struct s_struct
{
	pthread_t		*tids;
	pthread_mutex_t	*mutex;
}	t_struct;

void	*routine(void *arg)
{
	t_struct	estruct;
	(void)arg;

	estruct = *(t_struct *)arg;
	pthread_mutex_lock(estruct.mutex);
	usleep(100000);
	printf("HOLA!\n");
	usleep(100000);
	printf("QUE\n");
	usleep(100000);
	printf("TAL?\n");
	pthread_mutex_unlock(estruct.mutex);
	return (NULL);
}

int	spawn(t_struct *estruct, int i)
{
	if (pthread_create(&(*estruct).tids[i], NULL, routine, (void *)estruct))
	{
		perror("eta m**rda");
		return (-1);
	}
	return (0);
}

int	despawn(t_struct *estruct, int i)
{
	int	j;

	j = pthread_join((*estruct).tids[i], NULL);
	if (j)
	{
		printf("j :%i\n", j);
		perror("eta otra weba");
		return (-1);
	}
	return (0);
}

int	spawner(int *args)
{
	int				i;
	t_struct		estruct;
	pthread_mutex_t	mutex;
	(void)args;

	i = 0;
	estruct.tids = malloc(sizeof(pthread_t) * args[0]);
	estruct.mutex = &mutex;
	pthread_mutex_init(estruct.mutex, NULL);
	while (i < args[0])
		spawn(&estruct, i++);
	i = 0;
	while (i < args[0])
		despawn(&estruct, i++);
	pthread_mutex_destroy(estruct.mutex);
	return (1);
}
