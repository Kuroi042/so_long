NAME = get_next_line.a
CC = gcc
AR = ar rcs

CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
SRC = get_next_line.c get_next_line_utils.c
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