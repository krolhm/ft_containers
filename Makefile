# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    MAkefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbourgea <rbourgea@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/16 18:38:36 by rbourgea          #+#    #+#              #
#    Updated: 2021/08/19 20:46:55 by rbourgea         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	executable

SRCS	=	main.cpp \
			*/*.cpp

OBJS	=	$(SRCS:.cpp=.o)

CC		=	clang++

CFLAGS	=	-Wall -Werror -Wextra -std=c++98

all:		$(NAME)

$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) $(OBJS) -o $@

%.o: %.cpp
			$(CC) $(CFLAGS) -o $@ -c $<

clean:
			rm -f $(OBJS)

fclean: 	clean
			rm -f $(NAME)

re: 		fclean all

.PHONY: 	clean all fclean re