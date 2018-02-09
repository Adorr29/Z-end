/*
** EPITECH PROJECT, 2017
** Z-end
** File description:
** entity.h
*/

#ifndef ENTITY_H_
#define ENTITY_H_

#include <stdbool.h>
#include "map.h"

typedef struct
{
	int vie;
	int x;
	int y;
	char type;
	int var1;
	int var2;
	int var3;
} entity_t;

entity_t *entity_get_from_map(map_t *map);
void entity_set_up(entity_t *entity, int x, int y, char type);
void entity_aff(sfRenderWindow *window, map_t *map, entity_t *entity);

#endif
