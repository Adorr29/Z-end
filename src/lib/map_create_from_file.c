/*
** EPITECH PROJECT, 2017
** Z-end
** File description:
** map_create_from_file.c
*/

#include <stdio.h>
#include <stdlib.h>
#include "map.h"

FILE *file_open(char *file_name, char *mod)
{
	FILE *file;

	file = fopen(file_name, mod);
	if (file == NULL) {
		printf("Error opening %s.\n", file_name);
		exit(84);
	}
	return (file);
}

void map_get_line(FILE *file, map_t *map, int j)
{
	for (int i = 0; i < map->nb_case_x; i++) {
		char c;
		int tmp = fscanf(file, "%c", &c);

		if (tmp == EOF || c == '\n') {
			fseek(file, -1, SEEK_CUR);
			break;
		}
		map->tab[i][j] = c;
	}
}

void map_clear(map_t *map, char c)
{
	for (int j = 0; j < map->nb_case_y; j++) {
		for (int i = 0; i < map->nb_case_x; i++)
			map->tab[i][j] = c;
	}
}

void map_malloc(map_t *map)
{
	map->tab = malloc(sizeof(char *) * map->nb_case_x);
	map->var = malloc(sizeof(int *) * map->nb_case_x);
	for (int i = 0; i < map->nb_case_x; i++) {
		map->tab[i] = malloc(sizeof(char) * map->nb_case_y);
		map->var[i] = malloc(sizeof(int) * map->nb_case_y);
	}
}

map_t map_create_from_file(char *file_name)
{
	map_t map;
	FILE *file = file_open(file_name, "r");

	fscanf(file, "%d %d", &map.nb_case_x, &map.nb_case_y);
	map_malloc(&map);
	map_clear(&map, ' ');
	for (int j = 0; j < map.nb_case_y; j++) {
		fseek(file, 1, SEEK_CUR);
		map_get_line(file, &map, j);
		for (int i = 0; i < map.nb_case_x; i++)
			map.var[i][j] = 0;
	}
	fclose(file);
	return (map);
}
