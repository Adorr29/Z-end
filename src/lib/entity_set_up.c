/*
** EPITECH PROJECT, 2017
** Z-end
** File description:
** entity_set_up.c
*/

#include <stdlib.h>
#include "entity.h"
#include "nb_entity.h"

void entity_set_up(entity_t *entity, int x, int y, char type)
{
	for (int i = 0; i < nb_entity; i++) {
		if (entity[i].vie <= 0) {
			entity[i].vie = 1;
			entity[i].x = x;
			entity[i].y = y;
			entity[i].type = type;
			entity[i].var1 = 0;
			entity[i].var2 = 0;
			entity[i].var3 = 0;
			break;
		}
	}
}
