# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jwilen <jwilen@student.hive.fi>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/20 06:02:26 by jwilen            #+#    #+#              #
#    Updated: 2020/07/27 17:19:24 by jwilen           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = 	ft_printf.c\
		machine.c\
		specifer.c\
		specifer_percent.c\
		specifer_c.c\
		specifer_s.c\
		specifer_d.c\
		specifer_d_alfa.c\
		specifer_d_beta.c\
		specifer_d_gamma.c\
		specifer_d_delta.c\
		specifer_d_epsilon.c\
		specifer_u.c\
		specifer_u_alfa.c\
		specifer_x.c\
		specifer_x_alfa.c\
		specifer_x_beta.c\
		specifer_x_delta.c\
		specifer_p.c\
		specifer_o.c\
		specifer_o_alfa.c\
		specifer_o_beta.c\
		specifer_o_delta.c\
		specifer_f.c\
		specifer_b.c\
		utilities.c\
		utilities_alfa.c\

SDIR = source

SRCS = $(addprefix $(SDIR)/, $(SRC))

OBJ = $(SRC:.c=.o)

CC = gcc 

FLAGS = -Wall -Wextra -Werror

HEADER = ./includes/ft_printf.h

LIB_NAME = libft.a
LIB_PATH = ./libft/
LIB = $(LIB_PATH)$(LIB_NAME)

COLOR_RESET = \033[0m
COLOR_PENDING = \033[01;33m
COLOR_SUCCESS = \033[1;32m
COLOR_DEFAULT = \033[1;34m

all: $(NAME)

$(NAME):
	@echo "$(LIB_NAME)     [$(COLOR_PENDING)Compiling...$(COLOR_RESET)]"
	@make -C $(LIB_PATH)
	@echo "\033[A\033[K\033[A"
	@echo "$(LIB_NAME) [$(COLOR_SUCCESS)OK$(COLOR_RESET)]"
	@echo "$(LIB_NAME)     [$(COLOR_PENDING)Copying to root...$(COLOR_RESET)]"
	@cp $(LIB) $(NAME)
	@echo "\033[A\033[K\033[A"
	@echo "$(LIB_NAME) [$(COLOR_SUCCESS)Copy to root OK$(COLOR_RESET)]"
	@echo "$(NAME)     [$(COLOR_PENDING)Compiling...$(COLOR_RESET)]"
	@$(CC) $(FLAGS) -I $(HEADER) -I $(LIB_PATH) -c $(SRCS)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "\033[A\033[K\033[A"
	@echo "$(NAME)     [$(COLOR_SUCCESS)OK$(COLOR_RESET)]"
	@echo "        [$(COLOR_SUCCESS)FINISHED$(COLOR_RESET)]"
	
norme:
	norminette .

run:
	$(CC) $(NAME) main.c -g
	./a.out

clean:
	@make -C $(LIB_PATH) clean
	@rm -f $(OBJ)

fclean: clean
	@make -C $(LIB_PATH) fclean
	@rm -rfv $(NAME)

debug: fclean
	@make -C $(LIB_PATH)
	@$(CC) $(FLAGS) ./main/main.c $(SRCS) $(LIB) -g -o $(NAME)

re: fclean all

.PHONY: all clean debug fclean norme re

