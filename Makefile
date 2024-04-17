CC = cc
CFLAGS = -Wall -Wextra -Werror -g
NAME = ft_printf_tester
INC = ../libftprintf.a

SRCS = \
	tester.c\
	print_all.c\

OBJS = $(SRCS:.c=.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS)

mandatory: 

bonus: 

%.o: %.c
	%(CC) $(CFLAGS) -c $<

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re:
	make fclean
	make all
