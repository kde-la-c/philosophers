# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kde-la-c <kde-la-c@student.42madrid.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/03 19:06:05 by kde-la-c          #+#    #+#              #
#    Updated: 2023/10/03 19:06:07 by kde-la-c         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= philo
NAME_DBG	= dbg
SRC			= philo.c \
			input.c \
			parsing.c \
			time.c \
			output.c \
			start_threads.c \
			stop_threads.c \
			routines.c
OBJS		= $(SRC:%.c=%.o)
INCLUDE		= philo.h
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
CFLAGS		+= -O2
# CFLAGS		+= -flto
# CFLAGS		+= -fsanitize=address
# CFLAGS		+= -fsanitize=leak
# CFLAGS		+= -fsanitize=thread
CFLAGS		+= -pthread
RM			= rm
RFLAGS		= -rf

all:		$(NAME)

$(NAME):	$(OBJS) $(INCLUDE)
			$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	$(RM) $(RFLAGS) $(OBJS)
	@echo "\033[0;31m--- RELINK ---\033[0m"
			@echo "\033[0;32m--- $(NAME) compiled successfully! ---\033[0m"

debug:		$(NAME_DBG)

$(NAME_DBG): $(SRC)
			$(CC) $(CFLAGS) -fdiagnostics-color=always -g3 $(SRC) -o $@

clean:
			$(RM) $(RFLAGS) $(OBJS)
			@echo "\033[0;32m--- Objects cleaned successfully! ---\033[0m"

fclean:		clean
			$(RM) $(RFLAGS) $(NAME)
			@echo "\033[0;32m--- Archive cleaned successfully! ---\033[0m"

re:			fclean all

.PHONY:		all clean fclean re debug m l t
