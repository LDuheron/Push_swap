#############################################

NAME := push_swap

#############################################

#############################################

SRC_DIR     := srcs
OBJ_DIR     := obj

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


SRCS        := $(SRCS:%=$(SRC_DIR)/%)
OBJS        := $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

CC          := clang
CFLAGS      := -Wall -Wextra -Werror -g3
CPPFLAGS    := -I include

#############################################

RM          := rm -f
MAKEFLAGS   += --no-print-directory
DIR_DUP     = mkdir -p $(@D)

#############################################

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)
	$(info CREATED $(NAME))

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(DIR_DUP)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<
	$(info CREATED $@)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

#############################################

.PHONY: all clean fclean re

.SILENT:

#############################################