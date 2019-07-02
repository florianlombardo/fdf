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
SRCS_FILES = main.c
SRCS = $(addprefix $(SRCS_DIR), $(SRCS_FILES))

OBJS_DIR = objs/
OBJS = $(addprefix $(OBJS_DIR), $(SRCS_FILES:.c=.o))

LIB_DIR = libft/
LIB_FILE = libft.a
LIB = $(addprefix $(LIB_DIR), $(LIB_FILE))

INCLUDE_DIR = includes/
INCLUDE_FILES = fdf.h
INCLUDE = $(addprefix $(INCLUDE_DIR), $(INCLUDE_FILES))

MLX_DIR = minilibx/
MLX_FILE = libmlx.a
MLX = $(addprefix $(MLX_DIR), $(MLX_FILE))

CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iincludes/
MLXFLAGS = -framework OpenGL -framework AppKit
RM = rm -rf

all: $(NAME)

$(NAME): $(LIB) $(MLX) $(OBJS) $(INCLUDE)
	@$(CC) $(CFLAGS) $(MLXFLAGS) $(OBJS) $(LIB) $(MLX) -o $(NAME)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c $(INCLUDE)
	@$(CC) $(CFLAGS) $(MLXFLAGS) -o $@ -c $<

$(LIB):
	@make -C $(LIB_DIR)

$(MLX):
	@make -C $(MLX_DIR)

clean:
	@make -C $(LIB_DIR) clean
	@make -C $(MLX_DIR) clean
	@$(RM) $(OBJS)

fclean: clean
	@make -C $(LIB_DIR) fclean
	@$(RM) $(NAME)

re: fclean all
