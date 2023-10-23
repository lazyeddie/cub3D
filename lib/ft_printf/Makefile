# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aapostol <aapostol@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/11 13:58:27 by aapostol          #+#    #+#              #
#    Updated: 2023/10/11 16:46:36 by aapostol         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

### VARIABLES

# archive
NAME 	= libftprintf.a

# compiler
CC 		= cc -g
CFLAGS 	= -Wall -Werror -Wextra
DEPFLAGS= -MP -MMD
AR 		= ar -rcs

# colors
NONE		='\033[0m'
GREEN		='\033[32m'
YELLOW		='\033[33m'
GRAY		='\033[2;37m'
CURSIVE		='\033[3m'

# source files
SRC =	ft_funcs1.c \
		ft_funcs2.c \
		ft_printf.c

# object files
OBJ 	= $(SRC:.c=.o)
OBJDIR	= obj/
OBJPATH = $(addprefix $(OBJDIR), $(OBJ))

# dependency files
# DEPDIR	= dep/
DEP		= $(patsubst %.c, %.d, $(SRC))
DEPDIR	= dep/
DEPPATH = $(addprefix $(DEPDIR), $(DEP))

### RULES

all: $(NAME)

$(NAME): $(OBJDIR) $(OBJPATH) $(DEPDIR)
	@ make -C ../libft
	@ cp ../libft/libft.a $@
	@ echo $(GRAY)"creating libftprintf archive... "$(NONE)
	$(AR) $@ $(OBJPATH)
	@ echo $(GREEN)"= l i b f t p r i n t f  a r c h i v e  r e a d y ="$(NONE)

$(OBJDIR):
	@ echo $(GRAY)"compiling ft_printf object files..."$(NONE)
	@ mkdir -p $@

$(OBJDIR)%.o: %.c
	$(CC) $(CFLAGS) $(DEPFLAGS) -c -o $@ $<

$(DEPDIR):
	@ mkdir -p $@

$(DEPDIR)%.d: $(OBJDIR)%.d
	@ mv $< $@
	
-include $(DEPPATH)

clean:	
	@ make clean -C ../libft
	@ echo -n $(GRAY)"removing ft_printf object files... "
	@ rm -rf $(OBJDIR) $(DEPDIR)
	@ echo $(YELLOW)"done"$(NONE)

fclean: clean
	@ make fclean -C ../libft
	@ echo -n $(GRAY)"removing libftprintf archive... "
	@ rm -f $(NAME)
	@ echo $(YELLOW)"done"$(NONE)

re:	fclean all

.PHONY: all clean fclean re
