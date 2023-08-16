NAME = fdf
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = algo_utils.c clavier.c cnct_utils.c conect.c controle.c projection.c main.c \
			read_from_file.c mouse.c need.c needs.c parsing.c
OBJ = $(SRC:.c=.o)
UTILS = utils/libft.a
UTILSD	= utils/ft_atoi_base.c \
			utils/ft_atoi.c \
			utils/ft_bzero.c \
			utils/ft_calloc.c \
			utils/ft_itoa.c \
			utils/ft_printf_utils.c \
			utils/ft_printf.c \
			utils/ft_putchar_fd.c \
			utils/ft_putendl_fd.c \
			utils/ft_putstr_fd.c \
			utils/ft_split.c \
			utils/ft_strchr.c \
			utils/ft_strjoin.c \
			utils/ft_strlen.c \
			utils/ft_strncmp.c \
			utils/ft_toupper.c \
			utils/get_next_line.c

MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit
INCLUDE = fdf.h keys.h struct.h utils/utils.h

all: $(NAME)


$(NAME): $(OBJ) $(UTILS) $(INCLUDE) $(UTILSD)
	$(CC) $(CFLAGS) -o $@ $(OBJ) $(UTILS) $(MLX_FLAGS)

$(UTILS):
	cd utils && $(MAKE)

bonus:	all

clean:
	cd utils && $(MAKE) clean
	rm -f $(OBJ)

fclean: clean
	cd utils && $(MAKE) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re