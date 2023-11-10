# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mtrautne <mtrautne@student.42wolfsburg.d>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/10 15:59:30 by mtrautne          #+#    #+#              #
#    Updated: 2023/11/10 15:59:30 by mtrautne         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic

NAME = convert

SRCS =	ScalarConverter.cpp \
		main.cpp

HDRS =	ScalarConverter.hpp

OBJS = $(SRCS:%.cpp=%.o)

all: $(NAME)

%.o: %.cpp $(HDRS)
	$(CXX) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CXX) $(CFLAGS) $^ -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re