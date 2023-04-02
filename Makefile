NAME = Solong

GNL_DIR = g_nl
GNL = $(GNL_DIR)/get_next_line.a

LIBFT_DIR = libft
LIBFT =  $(LIBFT_DIR)/libft.a

FT_PRINTF_DIR = ftprintf
FT_PRINTF =  $(FT_PRINTF_DIR)/ft_printf.a

LIBFT_SRC = $(addprefix libft/, *.c)
GNL_SRC = $(addprefix g_nl/, *.c)
FTP_SRC = $(addprefix ftprintf/, *.c)


CC = cc
CFLAGS = -Wall -Werror -Wextra

SRC_SO = map_reader.c awsd.c line_errors.c errors.c mlxfunctions.c path.c map_utils.c press_nd_coin.c drawing.c zab.c
OBJS_C = ${SRC_SO:.c=.o}

FRAMEWORKS = -framework OpenGL -framework AppKit


all:  $(NAME) 
 
$(NAME): $(SRC_SO) $(OBJS_C) $(LIBFT_SRC) $(GNL_SRC) $(FTP_SRC) $(LIBFT)  $(GNL)  $(FT_PRINTF)
	$(CC)  $(CFLAGS)  $(OBJS_C)  $(LIBFT)  $(GNL)  $(FT_PRINTF) -lmlx $(FRAMEWORKS) -o $(NAME)

$(LIBFT): $(LIBFT_SRC)
	@make   -C $(LIBFT_DIR)
$(GNL): $(GNL_SRC)
	@make    -C $(GNL_DIR)  
$(FT_PRINTF): $(FTP_SRC)
	@make   -C $(FT_PRINTF_DIR) 

clean :
	rm -rf  $(OBJS_C) 
	@make -C  $(GNL_DIR)  clean
	@make -C  $(LIBFT_DIR)  clean
	@make -C  $(FT_PRINTF_DIR)  clean

fclean : clean
	rm -rf $(NAME) 
	@make -C $(GNL_DIR) fclean
	@make -C $(LIBFT_DIR) fclean
	@make -C $(FT_PRINTF_DIR) fclean

re: fclean all

