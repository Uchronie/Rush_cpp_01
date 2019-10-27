.PHONY: fclean, re, all

.SUFFIXES:

NAME = test

CC = g++

VPATH = srcs:

SRCC = main.cpp OsModule.cpp SdlClass.cpp UserModule.cpp TimeModule.cpp CpuModule.cpp

CPPFLAGS = -Wall -Wextra -Werror $(shell sdl2-config --cflags)
LDFLAGS = $(shell sdl2-config --libs) -lm -lSDL2_ttf -I incs

all: $(NAME)

$(NAME): $(SRCC)
	$(CC) $(CPPFLAGS) $(LDFLAGS) -o $(NAME) $^

fclean:
	@ rm -f $(NAME)

re: fclean $(NAME)