.PHONY: fclean, re, all

.SUFFIXES:

NAME = test

CC = g++

SRCC = whatever.cpp

CFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(SRCC)
	@ $(CC) $(CFLAGS) -o $(NAME) $^

fclean:
	@ rm -f $(NAME)

re: fclean $(NAME)