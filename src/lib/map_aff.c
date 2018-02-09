/*
** EPITECH PROJECT, 2017
** Z-end
** File description:
** map_aff.c
*/

#include <stdlib.h>
#include "prototype.h"
#include "map.h"
#include "liens_texture.h"
#include "case_size.h"

void map_aff_if(sfRenderWindow *window, char c, sfVector2f pos)
{
	if (file_font_name_get(c) != NULL)
		aff(window, pos, file_font_name_get(c));
	if (file_name_get(c) != NULL)
		aff(window, pos, file_name_get(c));
}

void block_manage_if(char *t, int *v)
{
	char dif = 'a' - 'A';

	if (*t == 'M' || *t == 'm' || *t == 'F' || *t == 'f')
		*v += 1;
	*v == 90 && *t == 'f' && rand() % 4 != 0 ? *t = 'F' : 0;
	if (*v >= 100 && (*t == 'M' || *t == 'm' || *t == 'F')) {
		if (rand() % 2 || *t == 'F')
			*t >= 'a' && *t <= 'z' ? (*t -= dif) : (*t += dif);
	}
	*v >= 100 ? *v = 0 : 0;
}

void block_manage(map_t *map)
{
	for (int j = 0; j < map->nb_case_y; j++) {
		for (int i = 0; i < map->nb_case_x; i++)
			block_manage_if(&map->tab[i][j], &map->var[i][j]);
	}
}

void map_aff(sfRenderWindow *window, map_t *map)
{
	sfVector2u win_size = sfRenderWindow_getSize(window);

	block_manage(map);
	for (int j = 0; j < map->nb_case_y; j++) {
		for (int i = 0; i < map->nb_case_x; i++) {
			sfVector2f pos;

			pos.x = i * CASE_SIZE + CASE_SIZE / 2 + win_size.x / 2;
			pos.x -= map->nb_case_x * CASE_SIZE / 2;
			pos.y = j * CASE_SIZE + CASE_SIZE / 2 + win_size.y / 2;
			pos.y -= map->nb_case_y * CASE_SIZE / 2;
			map_aff_if(window, map->tab[i][j], pos);
		}
	}
}
