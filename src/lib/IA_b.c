/*
** EPITECH PROJECT, 2017
** Z-end
** File description:
** IA_b.c
*/

#include <stdlib.h>
#include "prototype.h"

void IA_b(map_t *map, entity_t *entity, entity_t *my, entity_t *cible)
{
	my->var1++;
	if (my->var1 >= 5) {
		sfVector2i path = pathfinding(map, my, cible);

		my->var1 = 0;
		my->x += path.x;
		my->y += path.y;
		my->var2++;
		my->var2 >= 20 ? my->vie = 0 : 0;
	}
}
