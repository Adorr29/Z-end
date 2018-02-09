/*
** EPITECH PROJECT, 2017
** Z-end
** File description:
** map_destroy.c
*/

#include <stdlib.h>
#include "map.h"

void map_destroy(map_t *map)
{
	for (int i = 0; i < map->nb_case_x; i++)
		free(map->tab[i]);
	free(map->tab);
	for (int i = 0; i < map->nb_case_x; i++)
		free(map->var[i]);
	free(map->var);
}
