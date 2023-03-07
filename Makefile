# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: noanvillaseque <noanvillaseque@student.42. +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/07 14:57:38 by noanvillase       #+#    #+#              #
#    Updated: 2023/03/07 15:15:27 by noanvillaseque   ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc
CCFLAG = -Wall -Wextra -Werror

RM = rm
RMFLAG = -f

SRC = 

OBJS = $(SRCS:.c=.o)

.c.o:
	$(CC) $(CCFLAG) -c $< -o $(<:.c=.o)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

all: $(NAME)

clean:
		$(RM) $(RMFLAG) $(OBJS)

fclean: clean
		$(RM) $(RMFLAG) $(NAME)

re: fclean all