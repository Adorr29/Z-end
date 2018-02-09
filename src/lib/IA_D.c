/*
** EPITECH PROJECT, 2017
** Z-end
** File description:
** IA_D.c
*/

#include <stdlib.h>
#include "prototype.h"

static void dir(map_t *map, entity_t *my)
{
	int x = 0;
	int y = 0;

	if (rand() % 2)
		x = rand() % 2 * 2 - 1;
	else
		y = rand() % 2 * 2 - 1;
	if (!(opaque_get(map->tab[my->x + x][my->y + y]))) {
		my->x += x;
		my->y += y;
	}
}

void IA_D(map_t *map, entity_t *entity, entity_t *my, entity_t *cible)
{
	my->var1++;
	if (my->var1 >= 30) {
		my->var1 = 0;
		if (rand() % 5 == 0) {
			my->type = 'd';
			entity_set_up(entity, my->x, my->y, 'd');
		}
		else
			dir(map, my);
	}
}
