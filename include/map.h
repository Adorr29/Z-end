/*
** EPITECH PROJECT, 2017
** Z-end
** File description:
** map.h
*/

#ifndef MAP_H_
#define MAP_H_

#include <SFML/Graphics.h>

typedef struct
{
	int nb_case_x;
	int nb_case_y;
	char **tab;
	int **var;
} map_t;

map_t map_create_from_file(char *file_name);
void map_destroy(map_t *map);
void map_aff(sfRenderWindow* window, map_t *map);

#endif
