# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: root <root@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/12 22:00:17 by mganchev          #+#    #+#              #
#    Updated: 2025/04/13 23:37:34 by root             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX = c++
CXXFLAGS = -g -Wall -Wextra -Werror -std=c++98 #-fsanitize=address

NAME = bureaucrat

SRCS = main.cpp \
	   Bureaucrat.cpp \
	   Form.cpp

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)
	
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@
		
$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)	

clean: 
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all