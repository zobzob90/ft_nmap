NAME	= ft_nmap

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
INCLUDES = -I inc/

SRCS	= src/main.c \
		  src/parsing.c \
		  src/scanner.c \
		  src/threads.c \
		  src/utils.c

OBJS	= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -lpthread

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
