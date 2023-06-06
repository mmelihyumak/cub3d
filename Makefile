                                                                        
RED			=	\033[0;31m
GREEN		=	\033[1;32m
YELLOW		=	\033[1;33m
BLUE		=	\033[0;34m
CYAN		=	\033[1;36m
RESET		=	\033[0m

SUBDIR 				=	utils get_line map_control
SRCS				=	$(wildcard *.c $(foreach fd, $(SUBDIR), $(fd)/*.c))
NAME				=	cub3d
CC					=	gcc
CFLAGS				=	-Wall -Werror -Wextra -g -I./minilibx#-fsanitize=address -g
LFLAGS				=	-framework AppKit -framework OpenGL -L./minilibx -lmlx
MLX					=	./minilibx/libmlx.a
RM					=	rm -f
OBJS_DIR			=	objs/
PROJECT_H			=	cub3d.h
OBJS 				=	$(SRCS:c=o)
OBJECTS_PREFIXED	= 	$(addprefix $(OBJS_DIR), $(OBJS))
LIBFT				= ./libft
UNIX_NAME	= $(shell uname -s)
LINKERS		= -lft -L$(LIBFT)

$(MLX) :
	make -C ./minilibx

$(OBJS_DIR)%.o : %.c $(PROJECT_H)
	@mkdir -p $(OBJS_DIR)
	@mkdir -p $(OBJS_DIR)utils $(OBJS_DIR)get_line $(OBJS_DIR)map_control
	@$(CC) $(CFLAGS) -c $< -o $@ 
	@printf	"\033[2K\r📶${RED}[DERLENİYOR! / COMPILING!]${RESET}"

$(NAME): $(OBJECTS_PREFIXED) makerun
	@$(CC) -o $(NAME) $(CFLAGS) $(LFLAGS) $(OBJECTS_PREFIXED) $(LINKERS)
	@echo "\n${CYAN} _ _ . _ . _|_  _ ||${CYAN}"
	@echo "${CYAN}| | ||| ||_\| |(/_||${CYAN}"
	@echo "${YELLOW}    rbozdemi & duzun${YELLOW}"
	@echo "\n✅ ${GREEN}Executable ${NAME} created and ready for use!${BLUE} -- >${RED} $(NAME) ${BLUE}< --${RESET}"

all:	$(MLX) ${NAME}

makerun:
	@make -C ./libft

clean:
	@make clean -C ./libft
	@rm -rf $(OBJS_DIR)
	@echo "🧽 $(GREEN)Minishell Clean: ${RED}Removed all the \".o\" files${RESET}"

fclean:	clean
	@make fclean -C ./libft 
	make clean -C ./minilibx
	@rm -f $(NAME) 
	@echo "🧽 $(GREEN)Minishell Fclean: ${RED}Removed the executables${RESET}"

re:	fclean all

.PHONY:		all clean fclean re