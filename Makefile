##
## EPITECH PROJECT, 2017
## make
## File description:
## make
##

CC	=	gcc -g3 -ofast

NAME	=	lzw

SRC	=	src/main.c						\
		src/pars_av_memset_struct.c		\
		src/master.c					\
		src/compress.c					\
		src/decompress.c				\
		src/error_msg.c					\
		src/usage.c						\
		src/print_res_file.c			\
		lib/my_strcmp.c					\
		lib/my_strstr.c					\
		lib/my_evil_str.c				\
		lib/int_to_char.c				\
		lib/tab_tool_next.c				\
		lib/my_getnbr.c					\
		lib/get_file.c					\
		lib/my_put_nbr.c				\
		lib/my_putstr.c					\
		lib/my_strdup.c					\
		lib/my_strlen.c					\

OBJ	=	$(SRC:.c=.o)

CFLAGS	+=	-I./include/ -W -Wextra -Wall

all: 		$(NAME)

$(NAME): 	$(OBJ)
		$(CC) -o $(NAME) $(OBJ)

clean:
		rm -f $(OBJ)

test:
		rm -f *.gc*
		rm -f src/*.gc*

fclean: 	clean coverage_clean
		rm -f $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
