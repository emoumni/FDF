CFLAGS = -Wall -Wextra -Werror

NAME =	libft.a

SRC = ft_split.c ft_strlen.c ft_strchr.c ft_split.c get_next_line.c ft_strjoin.c \
	ft_itoa.c ft_printf.c ft_printf_utils.c ft_putstr_fd.c ft_putchar_fd.c ft_atoi.c \
	ft_calloc.c ft_bzero.c ft_putendl_fd.c ft_atoi_base.c ft_toupper.c ft_strncmp.c get_utils.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@ar r $(NAME) $(OBJ)

%.o: %.c
	@cc $(FLAG) -c $<

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re