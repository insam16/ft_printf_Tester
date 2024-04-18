CC = cc
CFLAGS = -Wall# -Wextra -Werror -g
NAME = ft_printf_tester
SUBDIR = ../ft_printf
PRINTF = $(SUBDIR)/libftprintf.a

SRCS = \
	tester.c\
	print_all.c\
	get_next_line.c\

OBJS = $(SRCS:.c=.o)

.PHONY: all clean fclean re m b

all: $(NAME)

$(NAME): $(OBJS)
	cd $(SUBDIR); make re
	$(CC) $(CFLAGS) $(OBJS) $(PRINTF) -o $(NAME)

# m: $(OBJS)
# 	$(CC) $(CFLAGS) $(OBJS) $(PRINTF) -o $(NAME)

# b: $(OBJS)
# 	$(CC) $(CFLAGS) $(OBJS) $(PRINTF) -o $(NAME)

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
