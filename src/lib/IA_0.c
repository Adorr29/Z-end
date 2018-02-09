/*
** EPITECH PROJECT, 2017
** Z-end
** File description:
** IA_0.c
*/

#include <stdlib.h>
#include "prototype.h"

void IA_0(map_t *map, entity_t *entity, entity_t *my, entity_t *cible)
{
	sfVector2i dir = move_rand(map, my);

	my->var1++;
	my->x += dir.x;
	my->y += dir.y;
	my->var1 >= 2 ? my->vie = 0 : 0;
}
