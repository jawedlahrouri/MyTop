##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## makefile
##

NAME = libmy.a
EXEC = my_top



SRC	=	my_top.c \

OBJ  	=	 $(SRC:.c=.o)

LIB_OBJ =  $(LIB:.c=.o)

$(NAME):	$(LIB_OBJ)
		ar rcs $(NAME) $(LIB_OBJ)
		$(MAKE) clean
		gcc -g $(SRC) -Iinclude -L. -lmy -o $(EXEC)

$(EXEC): $(OBJ) $(NAME)
		gcc -o $(EXEC) $(OBJ) -Iinclude -L -lmy

all: 	$(NAME) $(EXEC)



clean:
		rm -f $(OBJ) $(LIB_OBJ)


fclean: clean
		rm -f $(NAME) $(TEST) $(OBJ)ç

re:
		$(MAKE) fclean
		$(MAKE) all
debug:
		$(MAKE) clean
		gcc -g $(SRC) -Iinclude -L. -lmy -o $(EXEC)
