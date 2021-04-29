NAME	=	libmlx.a

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

SRCS	+=	mlx_shaders.c
SRCS	+=	mlx_new_window.m
SRCS	+=	mlx_init_loop.m
SRCS	+=	mlx_new_image.m
SRCS	+=	mlx_xpm.c
SRCS	+=	mlx_int_str_to_wordtab.c
SRCS	+=	mlx_png.c
SRCS	+=	mlx_mouse.m

OBJS1	=	$(SRCS:.c=.o)
OBJS	=	$(OBJS1:.m=.o)

CFLAGS	+=	-O2
CFLAGS	+=	-DSTRINGPUTX11

CC		= @cc

all: $(NAME)

$(NAME):	$(OBJS)
	@ar -r $(NAME) $(OBJS)
	@ranlib $(NAME)
	@printf "\033[2K\r$(BLUE)$(NAME)$(RESET)$(BLUEE): $(GREEN)Compiled [√]$(RESET)\n"

clean:
	@rm -f $(NAME) $(OBJS) *~

re: clean all

.PHONY: all clean re