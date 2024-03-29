.PHONY: fclean, re, all

.SUFFIXES:

NAME = ft_gkrellm

CC = clang++

VPATH = srcs:

SRCC = 	main.cpp OsModule.cpp SdlClass.cpp UserModule.cpp TimeModule.cpp\
		CpuModule.cpp NcursesDisplay.cpp NetworkModule.cpp RamModule.cpp\
		CatModule.cpp

CPPFLAGS = -Wall -Wextra -Werror $(shell sdl2-config --cflags) -std=c++98
LDFLAGS = $(shell sdl2-config --libs) -lm -lSDL2_ttf -I incs -lncurses -g

all: $(NAME)

$(NAME): $(SRCC)
	$(CC) $(CPPFLAGS) $(LDFLAGS) -o $(NAME) $^

fclean:
	@ rm -f $(NAME)

re: fclean $(NAME)
