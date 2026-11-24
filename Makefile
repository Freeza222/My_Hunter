SRC	=	src/main.c	\
		src/init.c	\
		src/init_assets.c	\
		src/init_entities.c	\
		src/event.c	\
		src/update.c	\
		src/destroy.c	\
		src/draw.c	\

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-Wall -Wextra -I include/ -I lib/

NAME    =       my_hunter
LIB     =       lib/my/libmy.a

LDFLAGS =       -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio -L lib/my -lmy

all: lib $(NAME)

$(LIB):
	$(MAKE) -C lib/my

$(NAME): $(OBJ) $(LIB)
	$(CC) $(OBJ) -o $(NAME) $(LDFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C lib/my fclean

re:	fclean all

.PHONY:	all clean fclean re