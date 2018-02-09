/*
** EPITECH PROJECT, 2017
** Z-end
** File description:
** move_rand.c
*/

#include <stdlib.h>
#include "prototype.h"
#include "liens_texture.h"

static sfVector2i dir_con(map_t *map, entity_t *my, sfVector2i *dir, int tmp)
{
	int npa;
	sfVector2i con = {0, 0};

	if (tmp > 0) {
		npa = tmp > 0 ? rand() % tmp : 0;
		con.x += dir[npa].x;
		con.y += dir[npa].y;
		my->var2 = -dir[npa].x;
		my->var3 = -dir[npa].y;
	}
	else {
		my->var2 = 0;
		my->var3 = 0;
	}
	return (con);
}

static void move_rand_if(map_t *map, entity_t *my, sfVector2i *d, int *t)
{
	int op = opaque_get(c_font_get(my->type));

	if (opaque_get(map->tab[my->x - 1][my->y]) == op && my->var2 != -1) {
		d[*t].x = -1;
		*t += 1;
	}
	if (opaque_get(map->tab[my->x + 1][my->y]) == op && my->var2 != 1) {
		d[*t].x = 1;
		*t += 1;
	}
	if (opaque_get(map->tab[my->x][my->y - 1]) == op && my->var3 != -1) {
		d[*t].y = -1;
		*t += 1;
	}
	if (opaque_get(map->tab[my->x][my->y + 1]) == op && my->var3 != 1) {
		d[*t].y = 1;
		*t += 1;
	}
}

sfVector2i move_rand(map_t *map, entity_t *my)
{
	int tmp = 0;
	sfVector2i dir[] = {{0, 0}, {0, 0}, {0, 0}, {0, 0}};

	move_rand_if(map, my, dir, &tmp);
	return (dir_con(map, my, dir, tmp));
}
