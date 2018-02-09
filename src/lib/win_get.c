/*
** EPITECH PROJECT, 2017
** Z-end
** File description:
** win_get.c
*/

#include "prototype.h"
#include "nb_entity.h"

int win_get_if(map_t *map, entity_t *entity)
{
	if (entity->vie > 0 && entity->type == 'P') {
		if (map->tab[entity->x][entity->y] == 'S')
			return (1);
		return (0);
	}
	return (-1);
}

void player_dies_if(entity_t *player, entity_t *entity)
{
	if (entity->x == player->x && entity->y == player->y)
		player->vie--;
}

void player_dies_for(entity_t *player, entity_t *entity)
{
	for (int i = 0; i < nb_entity; i++) {
		if (entity[i].vie > 0 && entity[i].type != 'P')
			player_dies_if(player, &entity[i]);
	}
}

void player_dies(entity_t *entity)
{
	int player_id = 0;

	for (int i = 0; i < nb_entity; i++) {
		if (entity[i].vie > 0 && entity[i].type == 'P') {
			player_id = i;
			break;
		}
	}
	player_dies_for(&entity[player_id], entity);
}

int win_get(map_t *map, entity_t *entity)
{
	int win = -1;

	player_dies(entity);
	for (int i = 0; i < nb_entity; i++) {
		int tmp = win_get_if(map, &entity[i]);

		if (tmp == 1)
			return (1);
		else if (tmp == 0)
			win = 0;
	}
	return (win);
}
