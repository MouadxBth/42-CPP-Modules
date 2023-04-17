# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbouthai <mbouthai@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/11 15:45:46 by mbouthai          #+#    #+#              #
#    Updated: 2023/04/11 16:11:24 by mbouthai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= tests

SRCS	= Account.cpp tests.cpp

OBJS	= $(SRCS:.cpp=.o)

INCS	= Account.hpp

CC	= c++

CFLAGS	= -Wall -Wextra -Werror -g -std=c++98

all: $(NAME)

$(NAME): $(OBJS) $(INCS)
	@echo "Linking..."
	$(CC) $(CFLAGS) $(OBJS) -o $@

%.o: %.cpp %.hpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
