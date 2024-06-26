CC = cc
CFLAGS = -Wall -Wextra -Werror -g
CFLAGSSIMPLE = -Wall -g
NORM = norminette
NAME = ft_printf_tester
DIR = ft_printf_Tester
SUBDIR = ../ft_printf_working
PRINTF = $(SUBDIR)/libftprintf.a

SRC_PRINT = print_all.c

SRCS = \
	tester.c\
	get_next_line.c\
	print_all.c

OBJS = $(SRCS:.c=.o)\

.PHONY: all clean fclean re m b

all: $(NAME)

# cd $(SUBDIR); norminette *.c *.h
$(NAME): $(OBJS) $(PRT)
	cd $(SUBDIR); make re
	cd ../$(DIR); $(CC) $(CFLAGSSIMPLE) $(OBJS) $(PRINTF) -o $(NAME)

$(PRT): $(SRC_PRINT)
	$(CC) $(CFLAGS) -c $(SRC_PRINT)

$(FRT): $(SRC_PRINT)
	$(CC) $(CFLAGS) -c $(SRC_PRINT)

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

re:
	make fclean
	make all
