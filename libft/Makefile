# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chanhhon <chanhhon@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/20 16:33:02 by chanhhon          #+#    #+#              #
#    Updated: 2024/05/24 20:49:32 by chanhhon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libft.a
SRCS = ft_abs.c ft_count.c ft_strcmp.c \
ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c \
ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c \
ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c \
ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c \
ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
ft_printf.c ft_printf_base.c ft_format.c get_next_line.c get_next_line_utils.c
SRCS_BONUS = ft_lstadd_back_bonus.c ft_lstadd_front_bonus.c ft_lstclear_bonus.c \
ft_lstdelone_bonus.c ft_lstiter_bonus.c ft_lstlast_bonus.c ft_lstmap_bonus.c \
ft_lstnew_bonus.c ft_lstsize_bonus.c 
OBJS= $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

$(NAME) : all

all :	make_mandatory

bonus : make_bonus

make_mandatory : $(OBJS)
	@ar -rcs $(NAME) $^
	@touch $@

make_bonus : $(OBJS_BONUS) $(OBJS)
	@ar -rcs $(NAME) $^
	@touch $@

%.o :	%.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean :
	@rm -f $(OBJS) $(OBJS_BONUS)
	@rm -f make_bonus make_mandatory

fclean :	clean
	@rm -f $(NAME)

re :
	$(MAKE) fclean
	$(MAKE)	all

.PHONY : re fclean clean all bonus