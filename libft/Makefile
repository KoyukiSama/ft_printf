
NAME		:= libft.a
CC			:= gcc
CFLAGS		:= -Wall -Wextra -Werror

SRC_LBFT	:= ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
				ft_isprint.c ft_toupper.c ft_tolower.c ft_toint.c \
				ft_tochar.c ft_isspace.c \
				ft_memset.c ft_memcpy.c ft_memmove.c ft_memchr.c \
				ft_memcmp.c ft_bzero.c ft_calloc.c \
				ft_strlen.c ft_strlcpy.c ft_strlcat.c ft_strchr.c \
				ft_strrchr.c ft_strcmp.c ft_strncmp.c ft_strnstr.c \
				ft_strdup.c ft_str_mallocpy.c ft_substr.c ft_strjoin.c \
				ft_strtrim.c ft_split.c ft_atoi.c ft_isdigit.c ft_itoa.c ft_strmapi.c \
				ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
				ft_putnbr_fd.c

SRC_LKDLST	:= ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c \
				ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
				ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c

SRC_GNL		:= get_next_line_utils.c get_next_line.c

SRC_ARRLST	:= ft_arrlst_del.c ft_arrlst_get.c ft_arrlst_manage.c \
				ft_arrlst_set.c ft_arrlst_utils.c

OBJ_LBFT 	:= $(SRC_LBFT:.c=.o)
OBJ_LKDLST 	:= $(SRC_LKDLST:.c=.o)
OBJ_GNL		:= $(SRC_GNL:.c=.o)
OBJ_ARRLST	:= $(SRC_ARRLST:.c=.o)

OBJ := $(OBJ_LBFT) $(OBJ_ARRLST)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
