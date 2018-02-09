/*
** EPITECH PROJECT, 2017
** Z-end
** File description:
** IA_3.c
*/

#include <stdlib.h>
#include "prototype.h"

void IA_3(map_t *map, entity_t *entity, entity_t *my, entity_t *cible)
{
	my->var1++;
	if (my->var1 >= 100) {
		my->var1 = 0;
		map->tab[my->x][my->y] = '+';
		if (my->vie <= 3)
			entity_set_up(entity, my->x, my->y, 'E');
		my->type = '1';
	}
	if (my->var1 >= 10)
		entity_set_up(entity, my->x, my->y, 'b');
}
