/*
** EPITECH PROJECT, 2017
** Z-end
** File description:
** IA_T.c
*/

#include "prototype.h"

void IA_T(map_t *map, entity_t *entity, entity_t *my, entity_t *cible)
{
	my->var1++;
	if (my->var1 >= 25) {
		sfVector2i path = pathfinding(map, my, cible);

		my->var1 = 0;
		if (path.x == 0 && path.y == 0)
			path = move_rand(map, my);
		my->x += path.x;
		my->y += path.y;
	}
}
