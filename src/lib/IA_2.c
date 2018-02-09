/*
** EPITECH PROJECT, 2017
** Z-end
** File description:
** IA_2.c
*/

#include <stdlib.h>
#include "prototype.h"
#include "nb_entity.h"
#include "health_bar.h"

static void move_to_9(map_t *map, entity_t *entity, entity_t *my)
{
	sfVector2i path;
	int index = 0;

	for (int i = 0; i < nb_entity; i++) {
		if (entity[i].type == '9')
			index = i;
	}
	path = pathfinding(map, my, &entity[index]);
	my->x += path.x;
	my->y += path.y;
	if (path.x == 0 && path.y == 0) {
		my->var1 = 0;
		my->type = '1';
	}
}

static void multi_dash(entity_t *my, entity_t *cible)
{
	int d = abs(cible->x - my->x) + abs(cible->y - my->y);

	if ((cible->x == my->x || cible->y == my->y) && d <= 10) {
		int x = cible->x - my->x;
		int y = cible->y - my->y;

		x > 0 ? x = 1 : x < 0 ? x = -1 : 0;
		y > 0 ? y = 1 : y < 0 ? y = -1 : 0;
		if (my->var2 != x || my->var3 != y || my->var1 >= 19) {
			my->var1 = 5;
			my->var2 = x;
			my->var3 = y;
		}
	}
}

void IA_2(map_t *map, entity_t *entity, entity_t *my, entity_t *cible)
{
	my->var1++;
	if (my->var1 >= 20 && my->var1 % 2)
		move_to_9(map, entity, my);
	if (my->var1 >= 10 && my->var1 < 20) {
		my->x += my->var2;
		my->y += my->var3;
		my->x < 1 ? my->x = 1 : 0;
		my->y < 1 ? my->y = 1 : 0;
		my->x > map->nb_case_x - 2 ? my->x = map->nb_case_x - 2 : 0;
		my->y > map->nb_case_y - 2 ? my->y = map->nb_case_y - 2 : 0;
		my->vie <= 3 && my->var1 > 11 ? multi_dash(my, cible) : 0;
		if (map->tab[my->x][my->y] == 'p') {
			rect_var2 = (float)my->vie;
			my->vie--;
			rect_var1 = 10.0;
		}
		map->tab[my->x][my->y] = my->vie > 0 ? '.' : 'S';
	}
}
