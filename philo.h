/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kde-la-c <kde-la-c@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 19:09:44 by kde-la-c          #+#    #+#             */
/*   Updated: 2023/10/03 19:09:47 by kde-la-c         ###   ########.fr       */
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

// read args
int	read_args(int argc, char **argv);
int	parsing(int *args, int argc, char **argv);

// output
int	print_error(char *msg);

// utils
int	ft_isdigit(int c);
int	ft_atoi(const char *str);
size_t	ft_strlen(const char *s);

#endif
