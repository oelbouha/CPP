# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oelbouha <oelbouha@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/29 12:50:16 by oelbouha          #+#    #+#              #
#    Updated: 2023/11/08 01:53:20 by oelbouha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := PmergeMe
CC := c++
FLAGS := -std=c++98  -Wall -Wextra -Werror #-fsanitize=address -g
SRC := main.cpp  List.cpp debug.utils.cpp utils.cpp Vector.cpp

OBJ := $(SRC:.cpp=.o)
OBJ := $(addprefix obj/, $(OBJ))

all : $(NAME) run
 
 run:
	./PmergeMe 7 19 3 20 13 5 15 17 21 18 8 14 6 9 1 2 16 11 4 12 10 

obj/%.o:%.cpp
	@mkdir -p obj
	@$(CC) $(FLAGS) -c $< -o $@

$(NAME) : $(OBJ) 
	@$(CC) $(FLAGS) -o $@ $^

clean :
	@rm -rf $(OBJ)

fclean : clean
	@rm -rf $(NAME)
	@rm -rf obj

re : fclean all

.phony: re all fclean clean
