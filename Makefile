# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chanhhon <chanhhon@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/05 21:52:45 by chanhhon          #+#    #+#              #
#    Updated: 2024/07/06 17:24:08 by chanhhon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC 			=	cc
CFLAGS 		=	-Wall -Wextra -Werror
NAME 		=	push_swap
SRCS 	=	csfunc.c push_swap.c

all : $(NAME)

$(NAME) : $(OBJS)
	@make -C ./libft
	@$(CC) -o $(NAME) $(SRCS) ./libft/libft.a

clean :
	@make -C ./libft clean

fclean :	clean
	@make -C ./libft fclean
	@rm -rf $(NAME)

re :
	@make fclean
	@make	all

.PHONY : re fclean clean all bonus