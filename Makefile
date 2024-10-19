EXEC_DIR        =   src/parsing/
INIT_DIR		=	src/init/
CFLAGS          =   -Wall -Wextra -Werror -fsanitize=address
NAME            =   cub3d
LIBFT_DIR       =   libft
LIBFT           =   $(LIBFT_DIR)/libft.a
CC              =   cc
F_LFT           =   -L$(LIBFT_DIR) -lft
INC             =   -I$(LIBFT_DIR) -Iinclude
INCLUDE         =   include/cub3d.h

SRC             =   main.c \
                    $(EXEC_DIR)pars_file.c \
                    $(EXEC_DIR)pars_map.c \
                    $(EXEC_DIR)add_data.c \
                    $(EXEC_DIR)check_texture_colors.c \
                    $(EXEC_DIR)my_malloc.c \
                    $(EXEC_DIR)pars_walls.c \
                    $(EXEC_DIR)parsing_cub.c \
                    $(EXEC_DIR)parsing_utils.c \
					$(INIT_DIR)init.c \

OBJ             =   $(SRC:.c=.o)

all: $(LIBFT) $(NAME)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

%.o: %.c $(INCLUDE)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(F_LFT) $(CFLAGS) -o $(NAME)

clean:
	@make clean -C $(LIBFT_DIR)
	@rm -f $(OBJ)

fclean: clean
	@make fclean -C $(LIBFT_DIR)
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re $(LIBFT)
