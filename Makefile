
NAME		:= libftprintf.a
CC			:= cc
CFLAGS		:= -Wall -Wextra -Werror
INCLUDE		:= -I./include -I./libft

SRC_PF		:= ft_print.c pf_arrlst.c pf_bonus_conversion.c
				pf_set_flags.c pf_set_flags2.c pf_sometoa.c
OBJ_PF		:= $(SRC_PF:.c=.o)

DIR_LBFT	:= ./libft
LIBFT_A		:= $(DIR_LBFT)/libft.a

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(DIR_LBFT)
	ar rcs $(NAME) $(OBJ_PF) $(LIBFT_A)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	rm -f $(OBJ_PF)
	make -C $(DIR_LBFT) clean

fclean: clean
	rm -f $(NAME)
	make -C $(DIR_LBFT) fclean

re: fclean all

.PHONY: all clean fclean re
