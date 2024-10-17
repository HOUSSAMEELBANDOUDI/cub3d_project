EXEC_DIR		=	src/parsing/
CFLAGS			=	-Wall -Wextra -Werror
NAME			=	cub3d
LIBFT_DIR		=	libft
LIBFT			=	$(LIBFT_DIR)/libft.a
CC				=	cc
F_LFT			=	-L$(LIBFT_DIR) -lft
INC				=	-I$(LIBFT_DIR)
INCLUDE			=	include/cub3d.h
SRC				=	main.c c \ $(EXEC_DIR)pars_file.c $(EXEC_DIR)pars_map.c \

OBJ				=	$(SRC:.c=.o)

all				: $(LIBFT) $(NAME) 

$(LIBFT)		:
				@$(MAKE) -C $(LIBFT_DIR)

%.o				: %.c $(INCLUDE)
				$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

$(NAME)			: $(OBJ) 
				$(CC) $(OBJ) $(F_LFT) -lreadline $(CFLAGS) -o $(NAME)

clean			:
				@make clean -C $(LIBFT_DIR)
				@rm -f $(OBJ)

fclean			:	clean
				@make fclean -C $(LIBFT_DIR)
				@rm -f $(NAME)

re				: fclean all

.PHONY			: all clean fclean re $(LIBFT)