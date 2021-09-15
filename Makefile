# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbourgea <rbourgea@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/16 18:38:36 by rbourgea          #+#    #+#              #
#    Updated: 2021/09/14 15:43:10 by rbourgea         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

STL		=	1

FT		=	0

NAME	=	ft_containers

ifeq (STL == 1 && FT == 0)
	SRCS	=	tests/main_stl.cpp
endif

ifeq (STL == 0 && FT == 1)
	SRCS	=	tests/main_ft.cpp
endif

ifeq (STL == 1 && FT == 1)
	SRCS	=	tests/main.cpp	\
				tests/map_test.cpp \
				tests/vector_test.cpp
endif

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