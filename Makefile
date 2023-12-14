NAME		=	fdf

CFLAGS		=	-Wall -Wextra 

DIR_MINI	=	./mlx
DIR_LIBFT	=	./libft

SRC_MAIN	=	fdf.c						\
				fdf_util_err.c				\
				fdf_util.c					\
				fdf_mapping.c				\
				fdf_strlist.c				\
				fdf_coordinate.c			\
				fdf_color.c					\
				fdf_paint.c					\
				fdf_draw_wire.c				\
				fdf_draw_wire_util.c

OBJ_MAIN	=	$(SRC_MAIN:%.c=%.o)
OBJ_LIBFT	=	$(SRC_LIBFT:%.c=%.o)
LIBFT_A		=	$(DIR_LIBFT)/libft.a
MINILIB_A	=	libmlx.dylib

HEADER		=	./fdf.h						\

all: $(NAME)

libft: $(LIBFT_A)

minilibx: $(MINILIB_A)

$(LIBFT_A):
	cd $(DIR_LIBFT); make ; cd ../

$(MINILIB_A):
	cd $(DIR_MINI); make ; mv $(MINILIB_A) ../ ; cd ../


%.o: %.c $(HEADER)
	gcc -c $(CFLAGS) -o $@ $<


$(NAME): $(OBJ_MAIN) $(HEADER) $(LIBFT_A) $(MINILIB_A)
	gcc $(CFLAGS) $(OBJ_MAIN) -Lmlx -framework OpenGL -framework AppKit $(LIBFT_A) $(MINILIB_A) -o $(NAME)

clean: 
	rm -f $(OBJ_MAIN)

fclean: clean
	rm -f $(NAME) $(MINILIB_A) ; cd ./libft; make fclean ; cd ../mlx ; make clean; cd ../

re: fclean all