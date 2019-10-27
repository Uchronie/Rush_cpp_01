.PHONY: fclean, re, all

.SUFFIXES:

NAME = test

CC = g++

VPATH = srcs:

SRCC = main.cpp OsMonitor.cpp SdlClass.cpp UserModule.cpp

CPPFLAGS = -Wall -Wextra -Werror $(shell sdl2-config --cflags)
LDFLAGS = $(shell sdl2-config --libs) -lm -lSDL_ttf -g

all: $(NAME)

$(NAME): $(SRCC)
	$(CC) $(CPPFLAGS) $(LDFLAGS) -o $(NAME) $^

fclean:
	@ rm -f $(NAME)

re: fclean $(NAME)