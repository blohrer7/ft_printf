# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: blohrer <blohrer@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/29 10:58:28 by blohrer           #+#    #+#              #
#    Updated: 2024/10/29 11:01:44 by blohrer          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= libftprintf.a
CC 		= gcc
CFLAGS 	= -Wall -Wextra -Werror
AR = ar

SRC		=	

OBJ 	= $(SRC:.c=.o)

all: $(NAME)

bonus: $(BONUS:.c=.o)
	ar -r $(NAME) $?

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@


clean:
	rm -f $(OFILES)


fclean: clean
	rm -f $(NAME) $(OBFILES)


re: fclean all

.PHONY: all clean fclean re bonus
