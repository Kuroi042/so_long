NAME = Solong
GNL_DIR = get_next_line
GNL = $(GNL_DIR)/get_next_line.a

LIBFT_DIR = libft
LIBFT =  $(LIBFT_DIR)/libft.a

CC = cc
CFLAGS = -Wall -Werror -Wextra

SRC_SO = map_reader.c awsd.c errors.c errors2.c mlxfunctions.c path.c permettre.c press_nd_coin.c drawing.c
OBJS_C = ${SRC_SO:.c=.o}

FRAMEWORKS = -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(OBJS_C) $(LIBFT) $(GNL)
	@$(CC) $(CFLAGS) $(OBJS_C) $(LIBFT) $(GNL) -lmlx $(FRAMEWORKS) -o $(NAME)

$(GNL) :
	@make -C @$(GNL_DIR)
$(LIBFT):
	@make -C @$(LIBFT_DIR)

clean :
	rm -rf $(OBJS_C)
	@make clean -C $(GNL_DIR)
	@make clean -C $(LIBFT_DIR)

fclean : clean
	rm -rf $(NAME)
	@make -C $(GNL_DIR)  : fclean 
	@make -C $(LIBFT_DIR) : fclean 



