# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nvillase <nvillase@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/07 14:57:38 by noanvillase       #+#    #+#              #
#    Updated: 2023/03/10 11:06:51 by nvillase         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc
CCFLAG = -Wall -Wextra -Werror

RM = rm
RMFLAG = -f

SRC = 	ft_printf.c \
		ft_foction_printf.c

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