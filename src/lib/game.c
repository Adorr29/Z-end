/*
** EPITECH PROJECT, 2017
** Z-end
** File description:
** game.c
*/

#include <stdlib.h>
#include "prototype.h"
#include "entity.h"
#include "nb_entity.h"

float rect_var1;
float rect_var2;

int game(sfRenderWindow *window, map_t *map)
{
	char play;
	int win = 0;
	entity_t *entity = entity_get_from_map(map);

	rect_var1 = 0;
	rect_var2 = 10;
	while (sfRenderWindow_isOpen(window) && win == 0) {
		win = win_get(map, entity);
		sfRenderWindow_clear(window, sfBlack);
		play = play_get(window);
		entity_move(map, entity, play);
		map_aff(window, map);
		entity_aff(window, map, entity);
		sfRenderWindow_display(window);
	}
	free(entity);
	return (win);
}
