# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oelbouha <oelbouha@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/29 12:50:16 by oelbouha          #+#    #+#              #
#    Updated: 2023/08/26 22:21:37 by oelbouha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := Serializer
CC := c++
FLAGS := -std=c++98  -Wall -Wextra -Werror
SRC := main.cpp Base.cpp A.cpp B.cpp C.cpp
 
OBJ := $(SRC:.cpp=.o)
OBJ := $(addprefix obj/, $(OBJ))

all : $(NAME)

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
