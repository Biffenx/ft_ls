# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jochumwilen <jochumwilen@student.42.fr>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/16 08:50:12 by jwilen            #+#    #+#              #
#    Updated: 2020/08/25 08:13:41 by jochumwilen      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc

CFLAGS = -g -Wall -Wextra -Werror -I$(INC_DIR)

SRC_DIR = ./srcs/

SRCS = $(addprefix $(SRC_DIR), $(SRC))

SRC = ft_atoi.c ft_memset.c ft_strlcat.c ft_bzero.c ft_putchar.c ft_strlen.c \
	  ft_countwords.c ft_putchar_fd.c ft_strmap.c ft_getintlen.c ft_putendl.c \
	  ft_strmapi.c ft_isalnum.c ft_putendl_fd.c ft_strncat.c ft_isalpha.c \
	  ft_putnbr.c ft_strncmp.c ft_isascii.c ft_putnbr_fd.c ft_strncpy.c \
	  ft_isdigit.c ft_putstr.c ft_strnequ.c ft_islower.c ft_putstr_fd.c \
	  ft_strnew.c ft_isprint.c ft_strcat.c ft_strnstr.c ft_istherewhitespaces.c \
	  ft_strchr.c ft_strrchr.c ft_isupper.c ft_strclr.c ft_strsplit.c ft_itoa.c \
	  ft_strcmp.c ft_strstr.c ft_memalloc.c ft_strcpy.c ft_strsub.c ft_memccpy.c \
	  ft_strdel.c ft_strtrim.c ft_memchr.c ft_strdup.c ft_tolower.c ft_memcmp.c \
	  ft_strequ.c ft_toupper.c ft_memcpy.c ft_striter.c ft_wordlength.c \
	  ft_memdel.c ft_striteri.c ft_memmove.c ft_strjoin.c ft_lstnew.c \
	  ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c ft_lstmap.c \
	  get_next_line.c ft_word_count.c ft_isspace.c ft_abs.c ft_ftoa.c \
	  ft_strrev.c ft_itoa_b.c ft_itoa_umax.c ft_memset.c ft_pow.c ft_strlcat.c \
	  ft_toupper_str.c ft_putnchar.c ft_lstlen.c ft_lstappend.c\
	  ft_min.c \
	  ft_max.c \
	  ft_printf/ft_printf.c \
	  ft_printf/machine.c \
	  ft_printf/specifer.c \
	  ft_printf/specifer_c_alfa.c \
	  ft_printf/specifer_percent.c \
	  ft_printf/specifer_c.c \
	  ft_printf/specifer_s.c \
	  ft_printf/specifer_d.c \
	  ft_printf/specifer_d_alfa.c \
	  ft_printf/specifer_d_beta.c \
	  ft_printf/specifer_d_gamma.c \
	  ft_printf/specifer_d_delta.c \
	  ft_printf/specifer_d_epsilon.c \
	  ft_printf/specifer_u.c \
	  ft_printf/specifer_u_alfa.c \
	  ft_printf/specifer_x.c \
	  ft_printf/specifer_x_alfa.c \
	  ft_printf/specifer_x_beta.c \
	  ft_printf/specifer_x_delta.c \
	  ft_printf/specifer_p.c \
	  ft_printf/specifer_o.c \
	  ft_printf/specifer_o_alfa.c \
	  ft_printf/specifer_o_beta.c \
	  ft_printf/specifer_o_delta.c \
	  ft_printf/specifer_f.c \
	  ft_printf/specifer_b.c \
	  ft_printf/utilities.c \
	  ft_printf/utilities_alfa.c \
	

OBJ_DIR = ./obj/
OBJ_DIR_PRINTF = $(OBJ_DIR)ft_printf/
OBJS = $(addprefix $(OBJ_DIR), $(OBJ))
OBJ = $(SRC:.c=.o)

INC_DIR = ./includes/
INCS = $(addprefix $(INC_DIR), $(INC))
INC = libft.h ft_printf.h

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJS)
	@echo "[$(COLOR_PENDING)Creating $@$(COLOR_RESET)]"
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo "\033[A\033[K\033[A"
	@echo "Libft: [$(COLOR_SUCCESS)Object files created$(COLOR_RESET)]"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(INCS)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	@echo "Libft: [$(COLOR_SUCCESS)$(OBJ_DIR) was created$(RESET)]"
	@mkdir -p $(OBJ_DIR_PRINTF)
	@echo "Ft_printf: [$(COLOR_SUCCESS)$(OBJ_DIR) was created$(RESET)]"
	

clean:
	@rm -f $(OBJS)
	@echo "Libft: [$(COLOR_DELETE)Object files were removed$(COLOR_RESET)]"
	@rm -rf $(OBJ_DIR)
	@echo "Libft: [$(COLOR_DELETE)Objects folder was removed$(COLOR_RESET)]"

fclean: clean
	@rm -f $(NAME)
	@echo "[$(COLOR_SUCCESS)$(NAME) is no more$(COLOR_RESET)]"

re: fclean all

norme:
	norminette .

run:
	@$(CC) $(FLAGS) -I . -c main.c
	@$(CC) $(FLAGS) -o run main.o libft.a

.PHONY: all clean fclean re
