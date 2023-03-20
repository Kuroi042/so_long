NAME = ft_printf.a

CC = gcc
AR = ar rcs

CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
SRC = ft_putchar.c ft_printf.c ft_putstring.c ft_putnbr.c ft_putunsigned.c ft_puthexa.c ft_adress.c
OBJ = $(SRC:.c=.o)
all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) -c $(SRC)
	@$(AR) $@ $^



clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean re