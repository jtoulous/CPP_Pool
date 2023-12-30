NAME	= phonebook
CC		= c++
CFLAGS	= -Wall -Wextra -Werror -g -std=c++98

SRC		= ./main.cpp ./Phonebook.cpp

OBJ		= $(SRC:.cpp=.o)

all: $(NAME)

%.o: %.cpp
		$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
		 $(CC) $(OBJ) $(CFLAGS) -o $(NAME)

clean:
		rm -rf $(OBJ)

fclean: clean
		rm -rf $(NAME)

re: fclean all

.PHONY: re all fclean clean
