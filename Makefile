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
SRC			= philo.c
OBJS		= $(SRC:%.c=%.o)
INCLUDE		= philo.h
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm
RFLAGS		= -rf

all:		$(NAME)

$(NAME):	$(OBJS) $(INCLUDE)
			$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	$(RM) $(RFLAGS) $(OBJS)
			@echo "\033[0;32m--- $(NAME) compiled successfully! ---\033[0m"

l:			$(OBJS) $(INCLUDE)
			$(CC) $(CFLAGS) -fsanitize=leak -g3 $(OBJS) -o $(NAME)
			$(RM) $(RFLAGS) $(OBJS)
			@echo "\033[0;32m--- $(NAME) compiled successfully! ---\033[0m"

m:			$(OBJS) $(INCLUDE)
			$(CC) $(CFLAGS) -fsanitize=address -g3 $(OBJS) -o $(NAME)
			$(RM) $(RFLAGS) $(OBJS)
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

.PHONY:		all clean fclean re debug m l
