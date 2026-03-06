# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: varandri <varandri@student.42antananari    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/15 20:23:27 by varandri          #+#    #+#              #
#    Updated: 2026/03/06 23:05:48 by varandri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

PRINTF_DIR = ft_printf

SRC = main.c ft_push_swap.c ft_parse_input.c ft_ps_utils.c ft_ps_utils_1.c \
		ft_ps_utils_2.c ft_ps_simple.c ft_ps_few.c ft_ps_medium.c \
		ft_ps_medium_utils.c ft_ps_complex.c ft_ps_complex_utils.c \
		ft_ps_adaptive.c ft_lst_utils.c ft_lst_utils_1.c ft_lst_act_utils.c \
		ft_lst_flag_utils.c ft_input_verification.c \
		ft_input_verification_utils.c ft_push.c ft_swap.c ft_rotate.c \
		ft_rev_rotate.c ft_str_utils.c ft_str_utils_1.c ft_str_split.c \
		ft_str_join.c disorder_metric.c ft_benchmark.c

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