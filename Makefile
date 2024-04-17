CC = cc
CFLAGS = -Wall# -Wextra -Werror -g
NAME = ft_printf_tester
INC = ../libftprintf.a

SRCS = \
	tester.c\
	print_all.c\
	get_next_line.c\

OBJS = $(SRCS:.c=.o)

.PHONY: all clean fclean re m b

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

m: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS)

b: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
	rm -f fd_frt fd_prt

re:
	make fclean
	make all
