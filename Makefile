NAME = ft_ls

CC = gcc
FLAGS = -Wall -Wextra -Werror
LIBRARIES = -lft -L$(LIBFT_DIRECTORY)
INCLUDES = -I$(HEADERS_DIRECTORY) -I$(LIBFT_HEADERS)

LIBFT_DIRECTORY = ./libft/
LIBFT = $(LIBFT_DIRECTORY)libft.a
LIBFT_HEADERS = $(LIBFT_DIRECTORY)

HEADERS_DIRECTORY = ./includes/
HEADER_FILES = header.h
HEADERS = $(addprefix $(HEADERS_DIRECTORY), $(HEADER_FILES))

SOURCES_DIRECTORY = ./srcs/
SOURCE_FILES =		create_lists.c \
					error_exit.c \
					main.c \
					print.c \
					print_basic.c \
					read_lists.c \
					read_dir.c \
					utilities.c \
					long.c \
					sort_lists.c \
					sort_basic.c \
					sort_lists_alfa.c \
			
			


SOURCES = $(addprefix $(SOURCES_DIRECTORY), $(SOURCE_FILES))

OBJECTS_DIRECTORY = ./objects/
OBJECT_FILES = $(patsubst %.c, %.o, $(SOURCE_FILES))
OBJECTS	= $(addprefix $(OBJECTS_DIRECTORY), $(OBJECT_FILES))

GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

all: $(NAME)

$(NAME): $(LIBFT) $(OBJECTS_DIRECTORY) $(OBJECTS) $(OBJECTS_PS)
	@$(CC) $(FLAGS) $(LIBRARIES) $(INCLUDES) $(OBJECTS) -o $(NAME)
	@echo "\n$(NAME): $(GREEN)$(NAME) object files were created$(RESET)"
	@echo "$(NAME): $(GREEN)$(NAME) was created$(RESET)"

$(OBJECTS_DIRECTORY):
	@mkdir -p $(OBJECTS_DIRECTORY)
	@echo "$(NAME): $(GREEN)$(OBJECTS_DIRECTORY) was created$(RESET)"

$(OBJECTS_DIRECTORY)%.o : $(SOURCES_DIRECTORY)%.c $(HEADERS)
	@$(CC) $(FLAGS) -c $(INCLUDES) $< -o $@
	@echo "$(GREEN).$(RESET)\c"

$(LIBFT):
	@echo "$(NAME): $(GREEN)creating $(LIBFT)...$(RESET)"
	@$(MAKE) -sC $(LIBFT_DIRECTORY)
	@echo "$(NAME): $(GREEN)$(LIBFT) OK!$(RESET)"

run:
	$(OBJECTS_DIRECTORY) $(OBJECTS) $(OBJECTS_PS)
	@$(CC) $(FLAGS) $(LIBRARIES) $(INCLUDES) $(OBJECTS) -o $(NAME)
	@echo "\n$(NAME): $(GREEN)$(NAME) object files were created$(RESET)"
	@echo "$(NAME): $(GREEN)$(NAME) was created$(RESET)"

	$(OBJECTS_DIRECTORY):
	@mkdir -p $(OBJECTS_DIRECTORY)
	@echo "$(NAME): $(GREEN)$(OBJECTS_DIRECTORY) was created$(RESET)"

	$(OBJECTS_DIRECTORY)%.o : $(SOURCES_DIRECTORY)%.c $(HEADERS)
	@$(CC) $(FLAGS) -c $(INCLUDES) $< -o $@
	@echo "$(GREEN).$(RESET)\c"

lib:
	@echo "$(NAME): $(GREEN)creating $(LIBFT)...$(RESET)"
	@$(MAKE) -sC $(LIBFT_DIRECTORY)
	@echo "$(NAME): $(GREEN)$(LIBFT) OK!$(RESET)"

clean:
	@$(MAKE) -sC $(LIBFT_DIRECTORY) clean
	@rm -rf $(OBJECTS_DIRECTORY)
	@echo "$(NAME): [$(RED)object files were deleted$(RESET)]"

fclean: clean
	@rm -f $(LIBFT)
	@echo "$(NAME): [$(RED)$(LIBFT) was deleted$(RESET)]"
	@rm -f $(NAME)
	@echo "$(NAME): [$(RED)$(NAME) was deleted$(RESET)]"


re:
	@$(MAKE) fclean
	@$(MAKE) all

.PHONY: all clean fclean re
