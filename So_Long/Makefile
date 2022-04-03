# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgranate <mgranate@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/16 17:02:19 by mgranate          #+#    #+#              #
#    Updated: 2022/03/16 19:28:07 by mgranate         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= so_long.a

SRCS		=		

OBJS		= $(SRCS:.c=.o)

CC			= gcc

RM			= rm -f

CFLAGS		= -Wall -Werror -Wextra -Imlx -c -I.

.c.o:		$(OBJS)
				$(CC) -c $(CFLAGS) $< -o $(<:.c=.o) 

all:		$(NAME)

$(NAME):	$(OBJS)
				@ar rcs $(CC) $(OBJS) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
				$(RM) $(OBJS)

fclean: 	clean
				$(RM) $(NAME)

re: 		fclean all

bonus:		$(OBJS)
			ar rcs $(NAME) $(OBJS)

.PHONY: 	all clean fclean re bonus .c.o
