# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sohollar <sohollar@student.42paris.fr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/05 18:08:37 by sohollar          #+#    #+#              #
#    Updated: 2026/03/05 22:54:00 by sohollar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_SERVER		= server
NAME_CLIENT 	= client

CC 				= cc
CFLAGS 			= -g -g3 -Wall -Wextra -Werror -I .

SRCS_SERVER 	= server.c
SRCS_CLIENT 	= client.c

OBJS_SERVER		= $(SRCS_SERVER:.c=.o)
OBJS_CLIENT 	= $(SRCS_CLIENT:.c=.o)

LIBFT			= ./Libft/libft.a
PRINTF_FD		= ./Printf_fd/libftprintf_fd.a

all : $(NAME_SERVER) $(NAME_CLIENT)
re : fclean all
$(NAME_SERVER) : $(OBJS_SERVER) $(LIBFT) $(PRINTF_FD)
	$(CC) $(CFLAGS) -o $(NAME_SERVER) $^
$(NAME_CLIENT) : $(OBJS_CLIENT) $(LIBFT) $(PRINTF_FD)
	$(CC) $(CFLAGS) -o $(NAME_CLIENT) $^

$(LIBFT) :
	make -C Libft

$(PRINTF_FD) :
	make -C Printf_fd

%.o : %.c
	$(CC) $(CFLAGS) -o $@ -c $<

clean :
	make -C Libft clean
	make -C Printf_fd clean
	rm -rf $(OBJS_SERVER)
	rm -rf $(OBJS_CLIENT)

fclean : clean
	make -C Libft fclean
	make -C Printf_fd fclean
	rm -rf $(NAME_SERVER)
	rm -rf $(NAME_CLIENT)

.PHONY : all clean fclean re
