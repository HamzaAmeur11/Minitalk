# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hameur <hameur@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/11 16:37:21 by hameur            #+#    #+#              #
#    Updated: 2022/03/29 11:43:39 by hameur           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#____________Makefile____________#

#target: dependencies (or prerequisite)
#	action

NAME = libft.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRC =	ft_atoi.c\
 		ft_bzero.c\
		ft_isalnum.c\
		ft_isalpha.c\
		ft_isascii.c\
		ft_isdigit.c\
		ft_isprint.c\
		ft_memchr.c\
		ft_memcmp.c\
		ft_memcpy.c\
		ft_memmove.c\
		ft_memset.c\
		ft_strchr.c\
		ft_strlcat.c\
		ft_strlcpy.c\
		ft_strlen.c\
		ft_strncmp.c\
		ft_strnstr.c\
		ft_strrchr.c\
		ft_tolower.c\
		ft_toupper.c\
		ft_calloc.c\
		ft_strdup.c\
		ft_putchar_fd.c\
		ft_substr.c\
		ft_strjoin.c\
		ft_putstr_fd.c\
		ft_putnbr_fd.c\
		ft_putendl_fd.c\
		ft_strtrim.c\
		ft_striteri.c\
		ft_strmapi.c\
		ft_itoa.c\
		ft_split.c\

OBJECT = $(SRC:.c=.o)

all: $(NAME)


$(NAME): $(OBJECT)
	@ar -rc $(NAME) $(OBJECT)

%.o : %.c libft.h
	@$(CC) $(CFLAGS) -o $@ -c $<
# < "$@" is the name of the target being generated and "$<" the first dependencies (or prerequisite) >

clean:
	@rm -rf $(OBJECT)

fclean: clean
	@rm -rf $(NAME)

re: all clean

.PHONY = all clean fclean re
