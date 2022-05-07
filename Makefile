# ************************************************************************** # 
#  888888  .d8888b.   .d8888b.                    888                        # 
#    "88b d88P  Y88b d88P  Y88b                   888                        # 
#     888 888    888 Y88b.                        888                        # 
#     888 888         "Y888b.    8888b.  88888b.  888888 .d88b.  .d8888b     # 
#     888 888            "Y88b.     "88b 888 "88b 888   d88""88b 88K         # 
#     888 888    888       "888 .d888888 888  888 888   888  888 "Y8888b.    # 
#     88P Y88b  d88P Y88b  d88P 888  888 888  888 Y88b. Y88..88P      X88    # 
#     888  "Y8888P"   "Y8888P"  "Y888888 888  888  "Y888 "Y88P"   88888P'    # 
#   .d88P                                                                    # 
# .d88P"                                                                     #  
#888P"                                                                       # 
#                                                                            # 
# Programa:	Incorporaciones                                                  # 
# Descripción:	Nuevas incorporaciones de LPS                                # 
# Fecha:		7 - May - 2022                                               # 
# ************************************************************************** # 

NAME 		=	nuevo
OBJ_DIR		=	obj/
SRCS_DIR	=	sources/
SRCS		=	main.c \
				fn_aux.c

OBJS = $(addprefix $(OBJ_DIR), $(SRCS:.c=.o))

NOW			=	$(shell date +"%d-%m-%y %H:%M")

LFLAGS = -I includes/
CFLAGS = -Wall -Wextra -Werror
LDFLAGS = -lncurses -lreadline -L/usr/local/opt/readline/lib
CPPFLAGS = -I/usr/local/opt/readline/include
DEBUGGING = -ggdb
OPTIMIZING = -O3
CC = clang 
LINUX-CC = cc
RM = rm -rf
AR = ar rc
RANLIB = ranlib
NORM = /usr/bin/norminette

RESET = \033[0m
RED = \033[31m
GREEN = \033[32m
YELLOW = \033[33m
BLUE = \033[34m
PINK = \033[35m
CYAN = \033[36m



all: $(NAME)

$(OBJ_DIR)%.o : $(SRCS_DIR)%.c
		@echo Create: $(NAME) Object directory
		@mkdir -p $(OBJ_DIR)
		$(CC) -c $(CFLAGS) $(DEBUGGING) $(LFLAGS) $< -o $@
#		$(CC) -c $(CFLAGS) $(DEBUGGING) $(LFLAGS) $< -o $@ -pthread

$(NAME): $(OBJS)
		@echo "$(YELLOW)=========== Compilando $(NAME) ==========="
#		$(CC) $(CFLAGS) $(OBJS) $(LFLAGS) -o $(NAME) -pthread
		$(CC) $(CFLAGS) $(LDFLAGS) $(CPPFLAGS) $(OBJS) $(LFLAGS) $(LIB_DIR)$(LIBFT) -o $(NAME)
		@echo "=========== DONE ==========$(RESET)"
clean:
		@echo "$(PINK)========== CLEAN =========="
		$(RM) $(OBJ_DIR)
		$(RM) $(OBJS)
		@echo "$(PINK)=========== DONE ===========$(RESET)"
fclean: clean
		@echo "$(RED)========== FCLEAN =========="
		$(RM) $(NAME)
		@echo "$(RED)=========== DONE ===========$(RESET)"
git_push: fclean
		@echo "$(RED)========== GIT_PUSH =========="
		git add *
		git commit -m "Incorporaciones - $(NOW)"
		git push 
		git status
		@echo "$(RED)=========== DONE ===========$(RESET)"
bonus: all
re: fclean all
norm: all
		$(NORM) $(SRC);
