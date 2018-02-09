/*
** EPITECH PROJECT, 2017
** Z-end
** File description:
** IA_1.c
*/

#include <stdlib.h>
#include "prototype.h"
#include "nb_entity.h"

static void to(map_t *map, entity_t *entity, entity_t *my, entity_t *cible)
{
	sfVector2i path = pathfinding(map, my, cible);

	my->x += path.x;
	my->y += path.y;
	for (int i = 0; i < nb_entity; i++) {
		if (entity[i].type == '9') {
			entity[i].x = my->x;
			entity[i].y = my->y;
			break;
		}
	}
}

static void to_2(entity_t *my, int x, int y)
{
	x > 0 ? x = 1 : x < 0 ? x = -1 : 0;
	y > 0 ? y = 1 : y < 0 ? y = -1 : 0;
	my->var2 = x;
	my->var3 = y;
	my->type = '2';
}

void IA_1(map_t *map, entity_t *entity, entity_t *my, entity_t *cible)
{
	my->var1++;
	if (my->var1 >= (my->vie > 3 ? 10 : 5)) {
		int npa = rand() % (my->vie > 3 ? 80 : 40);
		int d = abs(cible->x - my->x) + abs(cible->y - my->y);
		bool can2 = (cible->x == my->x || cible->y == my->y);

		my->var1 = 0;
		if (npa <= 1)
			my->type = npa ? '3' : '4';
		else if (can2 && d > 1 && d <= 10) {
			npa = rand() % (my->vie > 3 ? 10 : 2);
			npa ? to_2(my, cible->x - my->x, cible->y - my->y) : 0;
			npa ? 0 : (my->type = (rand() % 3 ? '4' : '3'));
		}
		else
			to(map, entity, my, cible);
	}
}
