# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adrijime <adrijime@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/31 17:44:31 by adrijime          #+#    #+#              #
#    Updated: 2024/02/14 19:49:49 by adrijime         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#================================= COLORES ====================================#

DEL_LINE        =   \033[2K
ITALIC          =   \033[3m
BOLD            =   \033[1m
DEF_COLOR       =   \033[0;39m
GRAY            =   \033[0;90m
RED             =   \033[0;91m
GREEN           =   \033[0;92m
YELLOW          =   \033[0;93m
BLUE            =   \033[0;94m
MAGENTA         =   \033[0;95m
CYAN            =   \033[0;96m
WHITE           =   \033[0;97m
BLACK           =   \033[0;99m
ORANGE          =   \033[38;5;209m
BROWN           =   \033[38;2;184;143;29m
DARK_GRAY       =   \033[38;5;234m
MID_GRAY        =   \033[38;5;245m
DARK_GREEN      =   \033[38;2;75;179;82m
DARK_YELLOW     =   \033[38;5;143m

#================================ VARIABLES ===================================#

NAME	= libftprintf.a
CC		= cc
FLAGS	= -Wall -Wextra -Werror -MMD
RM 		= rm -rf
LIBC 	= ar -rcs

#=================================== SRC ======================================#

SRCF =	ft_printf.c \
		ft_printf_utils.c \
		ft_putnbr.c

#=============================== DIRECTORIES ==================================#

DIR_OBJ = objects

OBJ = $(addprefix $(DIR_OBJ)/, $(SRCF:.c=.o))

#================================= RULES ======================================#

all: dir $(NAME)
-include $(DEP)

dir:
		mkdir -p $(DIR_OBJ)
		echo "$(YELLOW)💾== Directory created objects and dependencies ==💾$(DEF_COLOR)"

$(DIR_OBJ)/%.o: %.c Makefile libft.h | $(DIR_OBJ)
		$(CC) $(FLAGS) -c $< -o $@
		
$(NAME): $(OBJ) Makefile printf.h
		$(LIBC) $@ $<
		echo "$(GREEN)✅=== All compiled with flags, created libftprintf.a ===🖥$(DEF_COLOR)"

#================================= CLEAN ======================================#

clean:
		$(RM) $(DIR_OBJ)
		echo "🧨$(ORANGE)========== Deleted directory objects! ==========🧨$(DEF_COLOR)"

fclean: clean
		$(RM) $(NAME)
		echo "🧯$(RED)== objects dependencies and directory deleted ==🧯$(DEF_COLOR)"

re: fclean all

#================================== PHONY =====================================#

.PHONY: all clean fclean re

.SILENT: