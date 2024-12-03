##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## makefile
##
pathdir = src/lib

NAME = libmy

SRC	=	src/display_time.c \
		$(pathdir)/my_compute_power_rec.c \
		$(pathdir)/my_compute_square_root.c \
		$(pathdir)/my_isneg.c \
		$(pathdir)/my_put_nbr.c \
		$(pathdir)/my_putchar.c \
		$(pathdir)/my_putstr.c \
		$(pathdir)/my_revstr.c \
		$(pathdir)/my_strcat.c \
		$(pathdir)/my_strcpy.c \
		$(pathdir)/my_strlen.c \
		$(pathdir)/my_strncat.c \
		$(pathdir)/my_strncpy.c \
		$(pathdir)/flag_c.c \
		$(pathdir)/flag_d.c \
		$(pathdir)/flag_i.c \
		$(pathdir)/flag_o.c \
		$(pathdir)/flag_percent.c \
		$(pathdir)/flag_s.c \
		$(pathdir)/flag_x.c \
		$(pathdir)/flag_x2.c \
		$(pathdir)/my_printf.c \
		$(pathdir)/my_str_isnum.c \

OBJ  	=	 $(SRC:.c=.o)

TOP = my_top
CFLAGS = -Iinclude -L libmy -lncurses

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
