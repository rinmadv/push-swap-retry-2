# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: madavid <madavid@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/28 22:25:01 by marine            #+#    #+#              #
#    Updated: 2023/04/11 21:39:47 by madavid          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCDIR = srcs
BONUSDIR = bonus
INCDIR = header

# Compilation options
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3 -I$(INCDIR)

# Files
EXEC = push_swap
FILES = main.c \
		utils.c \
		check_arg.c \
		linked_lists_1.c \
		linked_lists_2.c \
		moves_push_swap.c \
		moves_rotate_reverse.c \
		sort_arg_two_three_five.c \
		sort_general.c \
		sort_general_indexing_presort.c \
		sort_general_match.c \
		sort_general_moves.c

EXEC_BONUS = checker
FILES_BONUS = check_arg_bonus.c \
				main_bonus.c \
				get_next_line/get_next_line.c \
				get_next_line/get_next_line_utils.c \
				moves_push_swap_bonus.c \
				linked_lists_1_bonus.c \
				moves_rotate_reverse_bonus.c \
				linked_lists_2_bonus.c \
				read_moves_bonus.c \
				utils_bonus.c

SRCS = $(addprefix srcs/,$(FILES))
SRCS_BONUS = $(addprefix bonus/,$(FILES_BONUS))

OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

# Rules
all: $(EXEC)

$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(EXEC)

bonus : $(EXEC_BONUS) 

$(EXEC_BONUS): $(OBJS_BONUS)
	$(CC) $(CFLAGS) $(OBJS_BONUS) -o $(EXEC_BONUS)

clean:
	rm -rf $(OBJS) $(OBJS_BONUS)

fclean: clean
	rm -f $(EXEC) $(EXEC_BONUS)

re: fclean all

.PHONY: all clean fclean re bonus
