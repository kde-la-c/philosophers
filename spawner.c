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

// pthread_mutex_t	mutex;

typedef struct s_struct
{
	int				inutil;
	pthread_t		tid1;
	pthread_t		tid2;
	pthread_mutex_t	*mutex;
}	t_struct;

void	*routine(void *arg)
{
	// pthread_mutex_t	mutex;
	(void)arg;

	// mutex = ((pthread_mutex_t *)arg)[3];
	pthread_mutex_lock(((pthread_mutex_t **)arg)[3]);
	usleep(100000);
	printf("HOLA!\n");
	usleep(100000);
	printf("QUE\n");
	usleep(100000);
	printf("TAL?\n");
	pthread_mutex_unlock(((pthread_mutex_t **)arg)[3]);
	return (NULL);
}

int	spawn(t_struct *estruct, int i)
{
	if (!i && pthread_create(&(*estruct).tid1, NULL, routine, (void *)estruct))
	{
		perror("eta m**rda");
		return (-1);
	}
	else if (i && pthread_create(&(*estruct).tid2, NULL, routine, (void *)estruct))
	{
		perror("eta otra m**rda");
		return (-1);
	}
	return (0);
}

int	despawn(t_struct *estruct, int i)
{
	int	j;

	if (!i)
		j = pthread_join((*estruct).tid1, NULL);
	else
		j = pthread_join((*estruct).tid2, NULL);
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
	t_struct	estruct;
	(void)args;

	estruct.inutil = 0;
	pthread_mutex_init(estruct.mutex, NULL);
	spawn(&estruct, 0);
	spawn(&estruct, 1);
	despawn(&estruct, 0);
	despawn(&estruct, 1);
	pthread_mutex_destroy(estruct.mutex);
	return (1);
}
