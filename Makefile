# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hameur <hameur@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/17 19:17:33 by hameur            #+#    #+#              #
#    Updated: 2022/04/14 12:51:53 by hameur           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#___________________________ Minitalk Makefile ___________________________#

NAME = server client 

BONUS = server_bonus client_bonus

CC = cc

CFLAGS = -Wall -Werror -Wextra

LIBFT = libft/libft.a

###___Colors___###
RED= \033[0;31m
GREEN= \033[0;32m
YELLOW= \033[1;33m
WHITE= \033[0;37m

all: client server bclean
	@echo "${YELLOW}Meking${GREEN} server & client ${WHITE}..."

server: server.c $(LIBFT)
	@$(CC) $(CFLAGS) server.c $(LIBFT) -o server

client: client.c $(LIBFT)
	@$(CC) $(CFLAGS) client.c $(LIBFT) -o client

$(LIBFT):
	make re -C libft

bonus: server_bonus client_bonus clean
	@echo "${YELLOW}Meking${GREEN} server_bonus & client_bonus ${WHITE}..."

server_bonus: server_bonus.c $(LIBFT)
	@$(CC) $(CFLAGS) server_bonus.c $(LIBFT) -o server_bonus

client_bonus: client_bonus.c $(LIBFT)
	@$(CC) $(CFLAGS) client_bonus.c $(LIBFT) -o client_bonus

clean:
	@rm -rf $(NAME)

bclean:
	@rm -rf $(BONUS)
	
fclean: clean bclean
	@echo "$(RED)Removing $(WHITE)Server $(GREEN)& $(WHITE)client..."
	@echo "$(RED)Removing $(WHITE)Server_bonus $(GREEN)& $(WHITE)Client_bonus..."

re: clean all

.PHONY = all clean fclean re



