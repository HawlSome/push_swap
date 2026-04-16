# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: varandri <varandri@student.42antananari    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/15 20:23:27 by varandri          #+#    #+#              #
#    Updated: 2026/04/16 15:24:04 by varandri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

PRINTF_DIR = ft_printf

SRC = main.c \
	algo_ft_ps_adaptive.c algo_ft_ps_complex.c algo_ft_ps_few.c \
	algo_ft_ps_medium.c algo_ft_ps_simple.c \
	helper_disorder_metric.c helper_ft_benchmark.c helper_ft_str_join.c \
	helper_ft_str_split.c \
	input_ft_parse.c input_ft_verification.c \
	move_ft_push.c move_ft_rev_rotate.c move_ft_rotate.c move_ft_swap.c \
	utils_ft_lst_1.c utils_ft_lst_act.c utils_ft_lst_flag.c utils_ft_lst.c \
	utils_ft_ps_1.c utils_ft_ps_2.c utils_ft_ps_complex.c utils_ft_ps_medium.c \
	utils_ft_ps.c utils_ft_str_1.c utils_ft_str.c utils_input_ft_verification.c\
	executer_ft_push_swap.c

OBJ = $(SRC:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror

LIBFTPRINTF = $(PRINTF_DIR)/libftprintf.a

all: $(NAME)

$(NAME): $(OBJ) $(LIBFTPRINTF)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFTPRINTF) -o $(NAME)

$(LIBFTPRINTF):
	$(MAKE) -C $(PRINTF_DIR)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) clean -C $(PRINTF_DIR)
	rm -f $(OBJ)

fclean: clean
	$(MAKE) fclean -C $(PRINTF_DIR)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re