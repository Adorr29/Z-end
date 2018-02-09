/*
** EPITECH PROJECT, 2017
** Z-end
** File description:
** IA_4.c
*/

#include <stdlib.h>
#include "prototype.h"

void IA_4(map_t *map, entity_t *entity, entity_t *my, entity_t *cible)
{
	int frec = (my->vie > 3 ? 5 : my->vie + 1);

	my->var1++;
	if (my->var1 >= 100)
		my->type = '1';
	else if (my->var1 >= 10 && my->var1 % frec == 0) {
		sfVector2i path = pathfinding(map, cible, my);

		cible->x += path.x;
		cible->y += path.y;
		if (my->x == cible->x && my->y == cible->y) {
			my->type = '1';
			my->vie < 10 ? my->vie++ : 0;
		}
		path.x == 0 && path.y == 0 ? my->type = '1' : 0;
	}
}
