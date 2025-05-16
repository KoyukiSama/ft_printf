
NAME		:= libftprintf.a
CC			:= cc
CFLAGS		:= -Wall -Wextra -Werror
INCLUDE		:= -I./include

DIR_SRC		:= ./src
SRC_PF		:= $(DIR_SRC)/ft_print.c \
				$(DIR_SRC)/pf_arrlst.c \
				$(DIR_SRC)/pf_bonus_conversion.c \
				$(DIR_SRC)/pf_set_flags.c \
				$(DIR_SRC)/pf_set_flags2.c \
				$(DIR_SRC)/pf_sometoa.c
OBJ_PF		:= $(SRC_PF:.c=.o)

DIR_LBFT	:= ./libft
LIBFT_A		:= $(DIR_LBFT)/libft.a

all: $(NAME)

$(NAME): $(OBJ_PF)
	make -C $(DIR_LBFT)
	ar rcs $(NAME) $(OBJ_PF) $(LIBFT_A)

$(DIR_SRC)/%.o: $(DIR_SRC)/%.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	rm -f $(OBJ_PF)
	make -C $(DIR_LBFT) clean

fclean: clean
	rm -f $(NAME)
	make -C $(DIR_LBFT) fclean

re: fclean all

.PHONY: all clean fclean re
