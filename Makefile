NAME			=	cub3D

BLACK			=	\033[0;30m
RED				=	\033[0;31m
GREEN			=	\033[0;32m
ORANGE			=	\033[0;33m
BLUE			=	\033[0;34m
PURPLE			=	\033[0;35m
CYAN			=	\033[0;36m
LIGHT_GRAY		=	\033[0;37m
DARK_GRAY		=	\033[1;30m
LIGHT_RED		=	\033[1;31m
LIGHT_GREEN		=	\033[1;32m
YELLOW			=	\033[1;33m
LIGHT_BLUE		=	\033[1;34m
LIGHT_PURPLE	=	\033[1;35m
LIGHT_CYAN		=	\033[1;36m
WHITE			=	\033[1;37m
NO_COLOR		=	\033[0m

-include sources.mk

BEST-LIBFT_PATH	=	./best-libft
LIBFT_PATH		=	./libft
LIBFT_LIB		=	$(LIBFT_PATH)/libft.a
MLX_PATH		=	./mlx
MLX_LIB			=	$(MLX_PATH)/libmlx.a

INCLUDES		=	./includes
OBJS			=	$(SRCS:.c=.o)

GCC				=	gcc
FLAGS			=	-Wall -Wextra -Werror -O3 -Ofast -flto -march=native -ffast-math
RM				=	rm -f

all: $(NAME)

.c.o:
	@echo "$(BLUE)Compiling .c in .o."
	@echo " "
	$(GCC) $(FLAGS) -I $(INCLUDES) -c $< -o $(<:.c=.o)
	@echo " "
	@echo "-------------------------------------------------------"
	@echo "$(NO_COLOR)"

$(BEST-LIBFT_PATH):
	@echo "$(PURPLE)Downloading best-libft. (can't find $(BEST-LIBFT_PATH) folder, getting it from github)"
	@echo " "
	git clone https://github.com/LoisDuplain/best-libft.git $(BEST-LIBFT_PATH)
	@echo " "
	@echo "-------------------------------------------------------"
	@echo "$(NO_COLOR)"

$(LIBFT_PATH): $(BEST-LIBFT_PATH)
	@echo "$(RED)Exporting libft. (can't find $(LIBFT_PATH) folder, exporting it from best-libft)"
	@echo " "
	$(MAKE) -C $(BEST-LIBFT_PATH) export
	@echo " "
	@echo "-------------------------------------------------------"
	@echo "$(NO_COLOR)"

$(LIBFT_LIB): $(LIBFT_PATH)
	@echo "$(ORANGE)Compiling libft. (creating libft.a)"
	@echo " "
	$(MAKE) -C $(LIBFT_PATH) all
	@echo " "
	@echo "-------------------------------------------------------"
	@echo "$(NO_COLOR)"

$(MLX_LIB): $(MLX_PATH)
	@echo "$(ORANGE)Compiling mlx. (creating libmlx.a)"
	@echo " "
	$(MAKE) -C $(MLX_PATH) all
	@echo " "
	@echo "-------------------------------------------------------"
	@echo "$(NO_COLOR)"

$(NAME): $(LIBFT_LIB) $(MLX_LIB) $(OBJS)
	@echo "$(GREEN)Compiling project. (creating executable)"
	@echo " "
	$(GCC) -L mlx -l mlx -framework OpenGL -framework AppKit $(FLAGS) -I $(INCLUDES) $(LIBFT_LIB) $(OBJS) -o $(NAME)
	@echo " "
	@echo "-------------------------------------------------------"
	@echo " "

oclean:
	@echo "$(LIGHT_RED)Cleaning all *.o in project."
	@echo " "
	$(RM) $(OBJS)
	@echo " "
	@echo "-------------------------------------------------------"
	@echo "$(NO_COLOR)"

clean: oclean
	@echo "$(LIGHT_RED)Cleaning all *.o in libft."
	@echo " "
	$(MAKE) -C $(LIBFT_PATH) clean
	@echo " "
	@echo "$(LIGHT_RED)Cleaning all *.o in mlx."
	@echo " "
	$(MAKE) -C $(MLX_PATH) clean
	@echo " "
	@echo "-------------------------------------------------------"
	@echo "$(NO_COLOR)"

fclean: clean
	@echo "$(RED)Full cleaning libft."
	@echo " "
	$(MAKE) -C $(LIBFT_PATH) fclean
	@echo " "
	@echo "$(LIGHT_RED)Full cleaning project."
	@echo " "
	$(RM) $(NAME)
	@echo " "
	@echo "-------------------------------------------------------"
	@echo "$(NO_COLOR)"

re: fclean all
	@echo "$(RED)Rebuilt correctly."

gmk:
	@echo "$(LIGHT_PURPLE)Generating sources makefile include."
	@echo " "
	@find sources -name '*.c' | sed 's/^/SRCS += /' > sources.mk
	@echo "-------------------------------------------------------"
	@echo "$(NO_COLOR)"

norminette: oclean
	@echo "$(GREEN)Checking norminette of includes."
	@echo " "
	norminette includes
	@echo " "
	@echo "$(LIGHT_GREEN)Checking norminette of sources."
	@echo " "
	norminette sources
	@echo " "
	@echo "-------------------------------------------------------"
	@echo "$(NO_COLOR)"

test: $(NAME)
	@echo "$(YELLOW)Makefile tests"
	@echo " "
	@echo "-------------------------------------------------------"
	@echo "$(NO_COLOR)"

end:
	@make fclean
	@make gmk
	@make all
	@make test
	@make norminette
	@make fclean
	@echo "$(GREEN)Pepared to be pushed."

.PHONY: all oclean clean fclean re gmk norminette test end
