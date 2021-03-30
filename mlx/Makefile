NAME	=	libmlx.a

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

all: $(NAME)

$(NAME):	$(OBJS)
	ar -r $(NAME) $(OBJS)
	ranlib $(NAME)

clean:
	rm -f $(NOM) $(OBJS) *~

re: clean all

.PHONY: all clean re