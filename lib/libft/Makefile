# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aapostol <aapostol@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/03 13:28:56 by aapostol          #+#    #+#              #
#    Updated: 2023/10/23 12:01:03 by aapostol         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

### VARIABLES

# Archive
NAME = libft.a

# Compiler
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
DEPFLAGS 	= -MP -MD

# Colors
NONE		='\033[0m'
GREEN		='\033[32m'
YELLOW		='\033[33m'
GRAY		='\033[2;37m'
CURSIVE		='\033[3m'

# Source files
SRC	= 	ft_atoi.c \
		ft_arrlen.c \
		ft_bzero.c \
		ft_calloc.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_itoa.c \
		ft_lstnew.c\
		ft_lstadd_front.c\
		ft_lstsize.c\
		ft_lstlast.c\
		ft_lstadd_back.c\
		ft_lstdelone.c\
		ft_lstclear.c\
		ft_lstiter.c\
		ft_lstmap.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_memset.c \
		ft_putchar_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_putstr_fd.c \
		ft_split.c \
		ft_strchr.c \
		ft_strdup.c \
		ft_striteri.c \
		ft_strjoin.c \
		ft_strlcat.c \
		ft_strlen.c \
		ft_strlcpy.c \
		ft_strmapi.c \
		ft_strncmp.c \
		ft_strnstr.c \
		ft_strrchr.c \
		ft_strtrim.c \
		ft_substr.c \
		ft_tolower.c \
		ft_toupper.c

# Object files
OBJ		= $(SRC:.c=.o)
OBJDIR	= obj/
OBJPATH	= $(addprefix $(OBJDIR), $(OBJ))

# Dependencies
DEP		= $(patsubst %.c, %.d, $(SRC))
DEPDIR	= dep/
DEPPATH = $(addprefix $(DEPDIR), $(DEP))

### RULES
all: $(NAME)

$(NAME): $(OBJDIR) $(OBJPATH) $(DEPDIR)
		@ echo $(GRAY)"creating libft archive... "$(NONE)
		ar -crs $@ $(OBJPATH)
		@ echo $(GREEN)"= l i b f t  a r c h i v e  r e a d y ="$(NONE)

$(OBJDIR):
		@ echo $(GRAY)"compiling libft object files... "$(NONE)
		@ mkdir -p $@

$(OBJDIR)%.o: %.c
		$(CC) $(CFLAGS) $(DEPFLAGS) -c -o $@ $^

$(DEPDIR):
	@ mkdir -p $@
	
$(DEPDIR)%.d: $(OBJDIR)%.d
	@ mv $< $@

-include $(DEPPATH)

clean:
		@ echo -n $(GRAY)"removing libft object files... "
		@ rm -rf $(OBJDIR) $(DEPDIR)
		@ echo $(YELLOW)"done"$(NONE)

fclean: clean
		@ echo -n $(GRAY)"removing libft archive... "
		@ rm -f $(NAME)
		@ echo $(YELLOW)"done"$(NONE)

re:	fclean all

.PHONY: all clean fclean re