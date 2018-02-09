/*
** EPITECH PROJECT, 2017
** Z-end
** File description:
** IA_E.c
*/

#include "prototype.h"

void IA_E(map_t *map, entity_t *entity, entity_t *my, entity_t *cible)
{
	my->var1++;
	if (my->var1 >= 20) {
		sfVector2i dir;

		my->var1 = 0;
		dir = move_rand(map, my);
		my->x += dir.x;
		my->y += dir.y;
	}
}
