NAME = Solong

GNL_DIR = gnl
GNL = $(GNL_DIR)/get_next_line.a

LIBFT_DIR = lbft
LIBFT =  $(LIBFT_DIR)/libft.a

FT_PRINTF_DIR = ftprintf
FT_PRINTF =  $(FT_PRINTF_DIR)/ft_printf.a


CC = cc
CFLAGS = -Wall -Werror -Wextra

SRC_SO = map_reader.c   awsd.c errors.c errors2.c mlxfunctions.c path.c permettre.c press_nd_coin.c drawing.c
OBJS_C = ${SRC_SO:.c=.o}

FRAMEWORKS = -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(OBJS_C) $(LIBFT) $(GNL) $(FT_PRINTF)
	@$(CC) $(CFLAGS) $(OBJS_C) $(LIBFT) $(GNL) $(FT_PRINTF) -lmlx $(FRAMEWORKS) -o $(NAME)

$(LIBFT):
	@make -C $(LIBFT_DIR) all
$(GNL) :
	@make -C $(GNL_DIR) all
$(FT_PRINTF):
	@make -C $(FT_PRINTF_DIR) all

clean :
	rm -rf $(OBJS_C)
	@make -C $(GNL_DIR) clean
	@make -C $(LIBFT_DIR) clean
	@make -C $(FT_PRINTF_DIR) clean

fclean : clean
	rm -rf $(NAME)
	@make -C $(GNL_DIR) fclean
	@make -C $(LIBFT_DIR) fclean
	@make -C $(FT_PRINTF_DIR) fclean



