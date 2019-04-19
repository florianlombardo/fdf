# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: flombard <flombard@student.le-101.fr>      +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2017/11/23 14:10:08 by flombard     #+#   ##    ##    #+#        #
#    Updated: 2018/04/23 17:58:09 by flombard    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME = fdf

SRCS_DIR = srcs/
SRCS_FILES = main.c utilities.c draw_iso.c draw_para.c parsing.c check_file.c \
			 special_cases.c
SRCS = $(addprefix $(SRCS_DIR), $(SRCS_FILES))

OBJS_DIR = objs/
OBJS = $(addprefix $(OBJS_DIR), $(SRCS_FILES:.c=.o))

LIB_DIR = libft/
LIB_FILE = libft.a
LIB = $(addprefix $(LIB_DIR), $(LIB_FILE))

MLX_DIR = minilibx/
MLX_FILE = libmlx.a
MLX = $(addprefix $(MLX_DIR), $(MLX_FILE))

RESET = \033[0m
RED = \033[1m\033[31m
GREEN = \033[1m\033[32m

CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iincludes/ -O2
MLXFLAGS = -framework OpenGL -framework AppKit
RM = rm -rf

all: $(NAME)

$(NAME): $(LIB) $(MLX) $(OBJS)
	@echo "$(GREEN)COMPILING FDF ...$(RESET)"
	@$(CC) $(CFLAGS) $(MLXFLAGS) $(OBJS) $(LIB) $(MLX) -o $(NAME)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
	@$(CC) $(CFLAGS) -o $@ -c $<

$(LIB):
	@make -C $(LIB_DIR)

$(MLX):
	@make -C $(MLX_DIR)

clean:
	@echo "$(RED)DELETING ...$(RESET)"
	@make -C $(LIB_DIR) clean
	@make -C $(MLX_DIR) clean
	@$(RM) $(OBJS)

fclean: clean
	@make -C $(LIB_DIR) fclean
	@$(RM) $(NAME)

re: fclean all
