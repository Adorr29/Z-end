##
## EPITECH PROJECT, 2017
## Z-end
## File description:
## Makfile
##

NAME	=	"Z-end"

SRCDIR	=	src/
LIBDIR	=	lib/

SRC	=	$(SRCDIR)main.c \
		$(SRCDIR)$(LIBDIR)game.c \
		$(SRCDIR)$(LIBDIR)play_get.c \
		$(SRCDIR)$(LIBDIR)opaque_get.c \
		$(SRCDIR)$(LIBDIR)win_get.c \
		$(SRCDIR)$(LIBDIR)entity_move.c \
		$(SRCDIR)$(LIBDIR)aff.c \
		$(SRCDIR)$(LIBDIR)move_rand.c \
		$(SRCDIR)$(LIBDIR)pathfinding.c \
		$(SRCDIR)$(LIBDIR)IA_E.c \
		$(SRCDIR)$(LIBDIR)IA_T.c \
		$(SRCDIR)$(LIBDIR)IA_D.c \
		$(SRCDIR)$(LIBDIR)IA_d.c \
		$(SRCDIR)$(LIBDIR)IA_B.c \
		$(SRCDIR)$(LIBDIR)IA_b.c \
		$(SRCDIR)$(LIBDIR)IA_K.c \
		$(SRCDIR)$(LIBDIR)IA_0.c \
		$(SRCDIR)$(LIBDIR)IA_1.c \
		$(SRCDIR)$(LIBDIR)IA_2.c \
		$(SRCDIR)$(LIBDIR)IA_3.c \
		$(SRCDIR)$(LIBDIR)IA_4.c \
		$(SRCDIR)$(LIBDIR)map_create_from_file.c \
		$(SRCDIR)$(LIBDIR)map_destroy.c \
		$(SRCDIR)$(LIBDIR)map_aff.c \
		$(SRCDIR)$(LIBDIR)entity_get_from_map.c \
		$(SRCDIR)$(LIBDIR)entity_set_up.c \
		$(SRCDIR)$(LIBDIR)entity_aff.c \
		$(SRCDIR)$(LIBDIR)c_font_get.c \
		$(SRCDIR)$(LIBDIR)file_font_name_get.c \
		$(SRCDIR)$(LIBDIR)file_name_get.c \

OBJ	=	$(SRC:.c=.o)

CFLAGS	+=	-I./include
CFLAGS	+=	-l csfml-system
CFLAGS	+=	-l csfml-window
CFLAGS	+=	-l csfml-graphics

all	:	$(NAME)

$(NAME)	:	$(OBJ)
		@cc -o $(NAME) $(OBJ) $(CFLAGS)

clean	:
		@rm -f $(OBJ)

fclean	:	clean
		@rm -f $(NAME)

re	:	fclean all
