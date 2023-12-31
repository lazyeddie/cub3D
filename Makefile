# executables
NAME		= cub3D
BONUS		= cub3D_bonus

# compiler
CC			= cc
CFLAGS		= -Werror -Wextra -Wall -g
DEPFLAGS	= -MP -MMD
MLXFLAGS	= -L./minilibx-linux -lmlx -lX11 -lXext
LINK		= -lm

# libft
LIB_DIR		=	lib/ft_printf/
LIB_NAME	=	libftprintf.a
LIB			=	$(LIB_DIR)$(LIB_NAME)

# minilibx
MLX_DIR		= minilibx-linux/
MLX_NAME	= libmlx.a
MLX			= $(MLX_DIR)$(MLX_NAME)

# include
INC			=	-I./inc -I./lib/ft_printf -I./lib/libft -I./minilibx-linux

# mandatory source files
SRC			= 	main.c \
				data_utils.c \
				data_utils2.c \
				data_create.c \
				data_check.c \
				data_map_check.c \
				data_sort.c \
				free_funcs.c \
				window.c \
				image.c \
				player.c \
				raycasting.c \
				draw.c \
				moves.c \
				rotation.c
SRCDIR		=	src/

# mandatory object files
OBJ			= $(SRC:%.c=%.o)
OBJDIR		= obj/
OBJPATH		= $(addprefix $(OBJDIR), $(OBJ))

# bonus source files
BSRC		=	main.c \
				data_utils.c \
				data_utils2.c \
				data_create.c \
				data_check.c \
				data_map_check.c \
				data_sort.c \
				free_funcs.c \
				window.c \
				image.c \
				player.c \
				raycasting.c \
				moves.c \
				rotation.c \
				draw.c \
				minimap.c \
				minimap_utils.c
BDIR		=	bonus/

# bonus object files
BOBJ			= $(BSRC:%.c=%.o)
BOBJDIR			= bobj/
BOBJPATH		= $(addprefix $(BOBJDIR), $(BOBJ))

# dependency files
DEP			= $(patsubst %.c, %.d, $(SRC))
# DEPDIR		= dep/
# DEPPATH 	= $(addprefix $(DEPDIR), $(DEP))

# colors
RED 		='\033[31m'
GREEN		='\033[32m'
YELLOW		='\033[33m'
BLUE		='\033[34m'
PINK		='\033[35m'
CYAN		='\033[36m'
WHITE		='\033[37m'
GRAY		='\033[237m'

BG_BLACK	='\033[40m'
BG_RED		='\033[41m'
BG_GREEN	='\033[42m'
BG_YELLOW	='\033[43m'
BG_BLUE		='\033[44m'
BG_PINK		='\033[45m'
BG_CYAN		='\033[46m'
BG_WHITE	='\033[47m'

BOLD		='\033[1m'
XXX			='\033[2m'
CURSIVE		='\033[3m'
UNDERLINE	='\033[4m'
RESET		='\033[0m'

# rules
all: $(LIB) $(NAME)

bonus: $(LIB) $(BONUS)

$(LIB):
	@echo $(GRAY)"Making libftprintf..."$(RESET)
	@make -sC $(LIB_DIR)

$(NAME): $(OBJDIR) $(OBJPATH)
	@$(CC) $(CFLAGS) $(INC) -o $(NAME) $(OBJPATH) $(LIB) $(MLXFLAGS) $(LINK)
	@echo $(BG_GREEN) $(XXX)"cub3D ready" $(RESET)

$(BONUS): $(BOBJDIR) $(BOBJPATH)
	@$(CC) $(CFLAGS) $(INC) -o $(BONUS) $(BOBJPATH) $(LIB) $(MLXFLAGS) $(LINK)
	@echo $(BG_GREEN) $(XXX)"cub3D_bonus ready" $(RESET)

$(OBJDIR)%.o: $(SRCDIR)%.c
	$(CC) $(CFLAGS) $(DEPFLAGS) $(INC) -c -o $@ $<

$(BOBJDIR)%.o: $(BDIR)%.c
	$(CC) $(CFLAGS) $(DEPFLAGS) $(INC) -c -o $@ $<

$(OBJDIR): 
	@mkdir -p $@

$(BOBJDIR): 
	@mkdir -p $@

#$(DEPDIR):
#	@mkdir -p $@
#	-@mv $(OBJDIR)*.d $@
#	-@mv $(BOBJDIR)*.d $@

-include $(DEPPATH)

clean:
	@rm -rf $(OBJDIR) $(BOBJDIR)
	@make clean -sC $(LIB_DIR)
	@echo $(GRAY) $(CURSIVE) "====> All object files removed successfully!" $(RESET)
	@echo $(YELLOW)"clean" $(RESET)

fclean: clean
	@rm -rf $(NAME) $(BONUS)
	@make fclean -sC $(LIB_DIR)
	@echo $(GRAY) $(CURSIVE) "====> All object files, libraries  and executables removed successfully!" $(RESET)
	@echo $(BG_YELLOW) $(XXX)"All clean" $(RESET)

re: fclean all

.PHONY:	all clean fclean re
