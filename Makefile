# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ksemele <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/27 16:34:56 by ksemele           #+#    #+#              #
#    Updated: 2020/01/14 17:11:53 by cghael           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc
FLAGS = -Wall -Werror -Wextra
LIBFT_FLAGS = -L./$(LIBFT_DIR) -lft

INCLUDES = -I$(HEADERS_DIR) -I$(LIBFT_HEADERS)

LIBFT = $(LIBFT_DIR)libft.a
LIBFT_DIR = libft/
LIBFT_HEADERS = $(LIBFT_DIR)inc/

HEADERS_LIST = ft_printf.h
HEADERS_DIR = includes/
HEADERS = $(addprefix $(HEADERS_DIR), $(HEADERS_LIST))

SRC_DIR = src/
SRC_LIST = ft_abs.c \
			ft_add_specials.c \
			ft_buff_finded_percent.c \
			ft_buff_free.c \
			ft_buff_no_percent.c \
			ft_buff_print_free.c \
			ft_buff_print_n_len.c \
			ft_buff_treated_percent.c \
			ft_bzero_buf_n_set_pointers.c \
			ft_choose_func.c \
			ft_dollar_arg.c \
			ft_dollar_treat.c \
			ft_error_exit.c \
			ft_final_print_n_free_rt_len.c \
			ft_find_digit.c \
			ft_find_in_def.c \
			ft_isbigger.c \
			ft_i64toa_base.c \
			ft_num_to_str.c \
			ft_parse_flags.c \
			ft_parse_spec.c \
			ft_parsing.c \
			ft_percent_treat.c \
			ft_precision_treat.c \
			ft_printf.c \
			ft_strcpy_dptp.c \
			ft_strpcpy.c \
			ft_width_treat.c \
			ft_u64toa_base.c \
			ft_c.c \
			ft_di.c \
			ft_o.c \
			ft_p.c \
			ft_s.c \
			ft_u.c \
			ft_x.c \
			ft_b.c \
			ft_f.c \
			ft_count_float.c \
			ft_get_integer.c \
			ft_get_divisional.c \
			ft_round_float.c \
			ft_exeption_treat.c \
			ft_integer_to_str.c \
			ft_add_dig_to_int.c \
			ft_width_n_precision.c \
			ft_add_float_to_str.c \
			ft_put_div_by_one.c

SRC = $(addprefix $(SRC_DIR), $(SRC_LIST))

OBJ_DIR = objects/
OBJ_LIST = $(patsubst %.c, %.o, $(SRC_LIST))
OBJ	= $(addprefix $(OBJ_DIR), $(OBJ_LIST))

# COLORS

GRN = \033[0;32m
RED = \033[0;31m
YEL = \033[1;33m
END = \033[0m

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ_DIR) $(OBJ)
	@cp $(LIBFT) ./$(NAME)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "\n$(NAME): $(GRN)*.o files created$(END)"
	@echo "$(NAME): $(GRN)$(NAME) created$(END)"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	@echo "$(NAME): $(GRN)$(OBJ_DIR) created$(END)"

$(OBJ_DIR)%.o : $(SRC_DIR)%.c $(HEADERS)
	@$(CC) $(FLAGS) -c $(INCLUDES) $< -o $@
	@echo "$(GRN).$(END)\c"

$(LIBFT):
	@echo "$(NAME): $(GRN)Creating $(LIBFT)...$(END)"
	@$(MAKE) -C $(LIBFT_DIR)

clean:
	@$(MAKE) -C $(LIBFT_DIR) clean
	@rm -rf $(OBJ_DIR)
	@echo "$(NAME): $(RED)$(OBJ_DIR) deleted$(END)"
	@echo "$(NAME): $(RED)*.o files deleted$(END)"

fclean: clean
	@rm -f $(LIBFT)
	@echo "$(NAME): $(RED)$(LIBFT) deleted$(END)"
	@rm -f $(NAME)
	@echo "$(NAME): $(RED)$(NAME) deleted$(END)"

re:
	@$(MAKE) fclean
	@$(MAKE) all

# TEST output main.c && libftprintf.a

test: $(NAME)
	@rm -f test.out
	@echo "\n$(RED)test.out delete$(END)"
	@$(CC) $(INCLUDES) -o test.out main.c -L. -lftprintf
	@echo "\n$(NAME): $(YEL)test.out created$(END)"
