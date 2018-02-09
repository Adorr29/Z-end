/*
** EPITECH PROJECT, 2017
** Z-end
** File description:
** pathfinding.c
*/

#include <stdlib.h>
#include "prototype.h"
#include "liens_texture.h"

static int tab_get_for(int nx, int ny, int **tab, int nb)
{
	int find = -1;
	bool n;

	for (int j = 1; j < ny - 1; j++) {
		for (int i = 1; i < nx - 1; i++) {
			n = tab[i][j] == nb;
			n && tab[i - 1][j] == -1 ? find = 0 : 0;
			n && tab[i + 1][j] == -1 ? find = 0 : 0;
			n && tab[i][j - 1] == -1 ? find = 0 : 0;
			n && tab[i][j + 1] == -1 ? find = 0 : 0;
			n && tab[i - 1][j] == -1 ? tab[i - 1][j] = nb + 1 : 0;
			n && tab[i + 1][j] == -1 ? tab[i + 1][j] = nb + 1 : 0;
			n && tab[i][j - 1] == -1 ? tab[i][j - 1] = nb + 1 : 0;
			n && tab[i][j + 1] == -1 ? tab[i][j + 1] = nb + 1 : 0;
		}
	}
	return (find);
}

static void tab_get(int nx, int ny, int **tab)
{
	int find = 0;

	for (int nb = 0; find == 0; nb++)
		find = tab_get_for(nx, ny, tab, nb);
}

static void path_get2(int **tab, sfVector2i *pos, sfVector2i *m, int find)
{
	tab[pos->x - 1][pos->y] == find - 1 ? m->x = -1 : 0;
	if (tab[pos->x + 1][pos->y] == find - 1) {
		m->x == 0 ? m->x = 1 : 0;
		m->x != 0 && rand() % 2 ? m->x = 1 : 0;
	}
	tab[pos->x][pos->y - 1] == find - 1 ? m->y = -1 : 0;
	if (tab[pos->x][pos->y + 1] == find - 1) {
		m->y == 0 ? m->y = 1 : 0;
		m->y != 0 && rand() % 2 ? m->y = 1 : 0;
	}
}

static sfVector2i path_get(int **tab, entity_t *my, entity_t *cible)
{
	sfVector2i pos;
	sfVector2i m = {0, 0};
	int npa = 0;

	pos.x = cible->x;
	pos.y = cible->y;
	for (int find = tab[pos.x][pos.y]; find > 0; find--) {
		npa = 0;
		m.x = 0;
		m.y = 0;
		path_get2(tab, &pos, &m, find);
		m.x != 0 && m.y != 0 ? npa = rand() % 2 * 2 - 1 : 0;
		npa <= 0 ? pos.x += m.x : 0;
		npa >= 0 ? pos.y += m.y : 0;
	}
	m.x = -m.x;
	m.y = -m.y;
	return (m);
}

sfVector2i pathfinding(map_t *map, entity_t *my, entity_t *cible)
{
	int **tab;
	bool t = opaque_get(c_font_get(my->type));
	sfVector2i path = {0, 0};

	tab = malloc(sizeof(int *) * map->nb_case_x);
	for (int i = 0; i < map->nb_case_x; i++) {
		tab[i] = malloc(sizeof(int) * map->nb_case_y);
		for (int j = 0; j < map->nb_case_y; j++)
			tab[i][j] = opaque_get(map->tab[i][j]) != t ? -2 : -1;
	}
	tab[my->x][my->y] = 0;
	tab_get(map->nb_case_x, map->nb_case_y, tab);
	path = path_get(tab, my, cible);
	for (int i = 0; i < map->nb_case_x; i++)
		free(tab[i]);
	free(tab);
	return (path);
}
