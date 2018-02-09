/*
** EPITECH PROJECT, 2017
** Z-end
** File description:
** IA_K.c
*/

#include <stdlib.h>
#include "prototype.h"

static void move2(map_t *map, entity_t *entity, entity_t *my, entity_t *cible)
{
	sfVector2i path;

	cible->y--;
	path = pathfinding(map, my, cible);
	my->x += path.x;
	my->y += path.y;
	cible->y++;
	if (path.x == 0 && path.y == 0) {
		cible->y++;
		path = pathfinding(map, my, cible);
		my->x += path.x;
		my->y += path.y;
		cible->y--;
	}
}

static void move1(map_t *map, entity_t *entity, entity_t *my, entity_t *cible)
{
	sfVector2i path;

	my->var1 = 0;
	cible->x--;
	path = pathfinding(map, my, cible);
	my->x += path.x;
	my->y += path.y;
	cible->x++;
	if (path.x == 0 && path.y == 0) {
		cible->x++;
		path = pathfinding(map, my, cible);
		my->x += path.x;
		my->y += path.y;
		cible->x--;
	}
	if (path.x == 0 && path.y == 0)
		move2(map, entity, my, cible);
}

void IA_K(map_t *map, entity_t *entity, entity_t *my, entity_t *cible)
{
	my->var1++;
	if (my->var1 >= 10) {
		sfVector2i df = {cible->x - my->x, cible->y - my->y};

		if (abs(df.x) + abs(df.y) == 1) {
			cible->x -= df.x;
			cible->y -= df.y;
		}
		else
			move1(map, entity, my, cible);
	}
}
