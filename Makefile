################################################################################
#                                     COLORS                                   #
################################################################################
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

################################################################################
#                                     VARS	                                   #
################################################################################
NAME		= libftprintf.a
CC 		= cc
CFLAGS	= -Wall -Wextra -Werror -MMD
AR		= ar -rcs
HEADER	= ft_printf.h
SRCS = ft_printf.c printf_utils.c

################################################################################
#                                  OBJECTS&DEPS	                               #
################################################################################

OBJS		= $(addprefix obj/, ${SRCS:.c=.o})
DEP			= $(addprefix obj/, ${SRC:.c=.d})

################################################################################
#                                      RULES	                               #
################################################################################

all: ${NAME}

-include $(DEP)


${NAME}:	${OBJS}
			$(AR) ${NAME} $(OBJS)
			echo "🌈$(GREEN)= TODO COMPILADO! =$(DEF_COLOR)🥂"


obj/%.o: %.c $(HEADER) Makefile
			mkdir -p $(dir $@)
			$(CC) $(CFLAGS) -c $< -o $@

clean:
			rm -rf obj
			echo "🔥$(ORANGE)= ELIMINADA CARPETA OBJ =$(DEF_COLOR)🧯"

fclean:		clean
			rm -rf ${NAME}
			echo "🌎$(RED)= ELIMINADO .a =$(DEF_COLOR)☄️"

re:			fclean all

################################################################################
#                                      PHONY	                               #
################################################################################

.PHONY:		all clean fclean re bonus

.SILENT: