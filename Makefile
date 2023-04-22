NAME = push_swap

SRCS += ./Actions/actions_utils.c
SRCS += ./Actions/push.c
SRCS += ./Actions/swap.c
SRCS += ./Actions/reverse_rotate.c
SRCS += ./Actions/rotate.c
SRCS += ./Actions/list_utils.c
SRCS += check_input.c
SRCS += check_input_utils.c
SRCS += clean.c
SRCS += init_stacks.c
SRCS += insert_in_a.c
SRCS += main.c
SRCS += moves.c
SRCS += position.c
SRCS += pre_sort.c
SRCS += push_swap.c
SRCS += push_swap_utils.c

CFLAGS = -Wall -Werror -Wextra -g3
CC = cc
RM = rm -rf

OBJS = $(SRCS:.c=.o)

### RULES

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o: %.cs
	$(CC) $(CFLAGS) -c $^ -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

.SILENT:
