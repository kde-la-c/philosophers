/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kde-la-c <kde-la-c@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 16:46:18 by kde-la-c          #+#    #+#             */
/*   Updated: 2024/02/15 16:46:21 by kde-la-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

	# include <errno.h>

typedef pthread_mutex_t	t_mtx;
typedef pthread_t		t_thd;

typedef struct	s_data
{
	int		nb_philos;
	int		t_death;
	int		t_eat;
	int		t_sleep;
	int		nb_loops;
	int		starttime;
	t_thd	*philos;
	t_mtx	*forks;
	int		*st_forks;
	t_mtx	print;
	t_mtx	start;
}	t_data;

typedef struct	s_philo
{
	t_data	*data;
	int		id;
	int		lfork;
	int		rfork;
	int		lastmeal;
	int		mealcount;
}	t_philo;



#endif
