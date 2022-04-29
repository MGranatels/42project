PS_NAME		=	push_swap
# C_NAME		=	checker

CC			=	clang

LIB_DIR		=	libft/
LIB			=	libft.a

PRINT_DIR	= printf/
PRINT		= libftprintf.a

DIR			=	srcs/
OBJ_DIR		=	obj/
SUB_DIR		=	obj/ps_srcs obj/c_srcs

FLAG		=	-c			\
				-Wall		\
				-Wextra		\
				-Werror

INCLUDE		=	-I include/				\
				-I $(LIB_DIR)			\
				-I $(PRINT_DIR)

RM			=	/bin/rm -f

PS_FILES	=	commands.c			\
				nodes.c				\
				operations.c		\
				operations2.c		\
				operations3.c		\
				push_swap.c			\
				sorting_alg.c		\
				check_arguments.c	\
				short_sort_alg.c    \
				check_sorting.c		\
				sort_big.c			\
				array.c

# C_FILES		=	c_srcs/c_main.c	

PS_SRCS		=	$(addprefix $(DIR), $(PS_FILES))
# C_SRCS		=	$(addprefix $(DIR), $(C_FILES))
PS_OBJ		=	$(PS_SRCS:$(DIR)%.c=$(OBJ_DIR)%.o)
# C_OBJ		=	$(C_SRCS:$(DIR)%.c=$(OBJ_DIR)%.o)

all			:	$(PS_NAME)	
# $(C_NAME) 

obj/%.o		:	srcs/%.c
				@mkdir -p $(OBJ_DIR) $(SUB_DIR)
				$(CC) -g $(FLAG) $(INCLUDE) $< -o $@

$(LIB)		:	
				@$(MAKE) -C $(LIB_DIR)
				/bin/mv $(LIB_DIR)$(LIB) .

$(PRINT)		:	
				@$(MAKE) -C $(PRINT_DIR)
				/bin/mv $(PRINT_DIR)$(PRINT) .

$(PS_NAME)	:	$(PS_OBJ) $(LIB) $(PRINT)
				$(CC) -o $@ $^

# $(C_NAME)	:	$(C_OBJ) $(LIB)
				# $(CC) -fsanitize=address -o $@ $^

clean		:	
				for dir in $(MODULES); do			\
					@$(MAKE) clean -C $$dir;		\
				done
				@/bin/rm -rf $(OBJ_DIR)

fclean		:	clean
				@$(MAKE) fclean -C $(LIB_DIR)
				@$(RM) $(LIB)
				@$(MAKE) fclean -C $(PRINT_DIR)
				@$(RM) $(PRINT)
				@$(RM) $(PS_NAME)
				# @$(RM) $(C_NAME)

re			:	fclean all

.PHONY		:	all clean fclean re