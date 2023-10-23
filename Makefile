# executables
NAME		= cub3D

# compiler
CC			= cc -g
CFLAGS		= -Werror -Wextra -Wall
DEPFLAGS	= -MP -MMD
MLXFLAGS	= -lX11 -lXext -lmlx

# libft
LIB_DIR		=	lib/ft_printf/
LIB_NAME	=	libftprintf.a
LIB			=	$(LIB_DIR)$(LIB_NAME)

# minilibx
MLX_DIR		= minilibx-linux/
MLX_NAME	= libmlx.a
MLX			= $(MLX_DIR)$(MLX_NAME)

# include
# INC			=	-Lminilibx-linux -Llib

# include
INC			=	-I. -I./lib/ft_printf -I./lib/libft

# sources
SRC			= 	

# objects
OBJ			=	$(SRC:%.c=%.o)
OBJDIR		= obj/
OBJPATH		= $(addprefix $(OBJDIR), $(OBJ))

# colors
GREEN		='\033[32m'
YELLOW		='\033[33m'
COLOR4		='\033[34m'
COLOR5		='\033[35m'
COLOR6		='\033[36m'
COLOR7		='\033[37m'
COLOR8		='\033[38m'
GRAY		='\033[237m'
CURSIVE		='\033[3m'
RESET		='\033[0m'

# rules
all: $(LIB) $(MLX) $(NAME)

$(LIB):
	@echo $(GRAY) "Making libftprintf..." $(RESET)
	@make -sC $(LIB_DIR)

$(MLX):
	@echo $(GRAY) "Making MiniLibX..." $(RESET)
	@make all -sC $(MLX_DIR)
	@echo $(YELLOW) "MiniLibX ready" $(RESET)
	@echo $(COLOR4) "test COLOR4" $(RESET)
	@echo $(COLOR5) "test COLOR5" $(RESET)
	@echo $(COLOR6) "test COLOR6" $(RESET)
	@echo $(COLOR7) "test COLOR7" $(RESET)
	@echo $(COLOR8) "test COLOR8" $(RESET)

$(NAME): $(OBJDIR) $(OBJPATH)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJPATH) $(MLX) $(LIB) $(INC) $(MLXFLAGS)
	@echo $(GREEN) "cub3D ready" $(RESET)

$(OBJDIR)%.o: $(SRCDIR)%.c
	$(CC) $(CFLAGS) -c -o $@ $<

$(OBJDIR): 
	@mkdir -p $(OBJDIR)

clean:
	@rm -f $(OBJ)
	@make clean -C $(LIB_DIR)libft
	@make clean -C $(LIB_DIR)ft_printf
	@echo $(GRAY) $(CURSIVE) "====> All object files removed successfully!" $(RESET)

fclean: clean
	@rm -rf $(NAME) $(SBONUS) $(CBONUS)
	@make fclean -C $(LIB_DIR)/libft
	@make fclean -C $(LIB_DIR)/ft_printf
	@echo $(GRAY) $(CURSIVE) "====> All object files, libraries  and executables removed successfully!" $(RESET)

re: fclean all

.PHONY:	all clean fclean re
