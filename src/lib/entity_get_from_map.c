/*
** EPITECH PROJECT, 2017
** Z-end
** File description:
** entity_get_from_map.c
*/

#include <stdlib.h>
#include "entity.h"
#include "liens_texture.h"
#include "entity_type.h"
#include "nb_entity.h"

void entity9_set(entity_t *entity, sfVector2i *pos)
{
	entity->vie = 100;
	entity->x = pos->x;
	entity->y = pos->y;
	entity->type = '9';
	entity->var1 = 0;
	entity->var2 = 0;
	entity->var3 = 0;
}

void entity_set(entity_t *entity, sfVector2i *pos, char type)
{
	for (int i = 0; i < nb_entity; i++) {
		if (entity[i].vie <= 0) {
			if (type == '1' && i + 1 < nb_entity) {
				entity9_set(&entity[i], pos);
				i++;
			}
			entity[i].vie = 1;
			type == 'B' ? entity[i].vie = 3 : 0;
			type == '1' ? entity[i].vie = 10 : 0;
			entity[i].x = pos->x;
			entity[i].y = pos->y;
			entity[i].type = type;
			entity[i].var1 = rand() % 30;
			entity[i].var2 = 0;
			entity[i].var3 = 0;
			break;
		}
	}
}

void entity_test(entity_t *entity, sfVector2i *pos, char *type)
{
	for (int i = 0; entity_type[i] != '\0'; i++) {
		if (*type == entity_type[i]) {
			entity_set(entity, pos, *type);
			*type = c_font_get(*type);
		}
	}
}

void entity_set_defult(entity_t *entity)
{
	for (int i = 0; i < nb_entity; i++) {
		entity[i].vie = 0;
		entity[i].x = 0;
		entity[i].y = 0;
		entity[i].type = '\0';
		entity[i].var1 = rand() % 30;
		entity[i].var2 = 0;
		entity[i].var3 = 0;
	}
}

entity_t *entity_get_from_map(map_t *map)
{
	entity_t *entity = malloc(sizeof(entity_t) * nb_entity);
	sfVector2i pos;

	entity_set_defult(entity);
	for (int j = 0; j < map->nb_case_y; j++) {
		for (int i = 0; i < map->nb_case_x; i++) {
			pos.x = i;
			pos.y = j;
			entity_test(entity, &pos, &map->tab[i][j]);
		}
	}
	return (entity);
}
