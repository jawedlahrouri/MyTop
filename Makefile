##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## makefile
##
SRC	=	src/my_top.c \

OBJ  	=	 $(SRC:.c=.o)

TOP = my_top
CFLAGS = -Iinclude -lncurses

$(TOP): $(OBJ)
		gcc $(OBJ) -o $(TOP) $(CFLAGS)

all: 	$(TOP)

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(TOP)

re:
		$(MAKE) fclean
		$(MAKE) all

debug:
		$(MAKE) clean
		gcc -g $(SRC) -o $(TOP) $(CFLAGS)
