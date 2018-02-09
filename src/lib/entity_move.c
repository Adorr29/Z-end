/*
** EPITECH PROJECT, 2017
** Z-end
** File description:
** entity_move.c
*/

#include <stdlib.h>
#include "prototype.h"
#include "nb_entity.h"
#include "liens_texture.h"

void player_move(map_t *map, entity_t *entity, entity_t *my, char play)
{
	int x = my->x;
	int y = my->y;

	if (map->tab[my->x][my->y] == '+') {
		my->var2++;
		map->tab[my->x][my->y] = c_font_get('+');
	}
	play == 'U' ? y-- : 0;
	play == 'D' ? y++ : 0;
	play == 'L' ? x-- : 0;
	play == 'R' ? x++ : 0;
	if (my->var2 > 0 && play == ' ' && map->tab[my->x][my->y] == '.') {
		map->tab[my->x][my->y] = 'p';
		my->var2--;
	}
	!(opaque_get(map->tab[x][y])) ? my->x = x : 0;
	!(opaque_get(map->tab[x][y])) ? my->y = y : 0;
}

void IA(map_t *map, entity_t *entity, entity_t *my, entity_t *cilbe)
{
	if (map->tab[my->x][my->y] == 'p') {
		map->tab[my->x][my->y] = c_font_get('p');
		my->vie--;
	}
	else {
		my->type == 'E' ? IA_E(map, entity, my, cilbe) : 0;
		my->type == 'T' ? IA_T(map, entity, my, cilbe) : 0;
		my->type == 'D' ? IA_D(map, entity, my, cilbe) : 0;
		my->type == 'd' ? IA_d(map, entity, my, cilbe) : 0;
		my->type == 'B' ? IA_B(map, entity, my, cilbe) : 0;
		my->type == 'b' ? IA_b(map, entity, my, cilbe) : 0;
		my->type == 'K' ? IA_K(map, entity, my, cilbe) : 0;
		my->type == '0' ? IA_0(map, entity, my, cilbe) : 0;
		my->type == '1' ? IA_1(map, entity, my, cilbe) : 0;
		my->type == '2' ? IA_2(map, entity, my, cilbe) : 0;
		my->type == '3' ? IA_3(map, entity, my, cilbe) : 0;
		my->type == '4' ? IA_4(map, entity, my, cilbe) : 0;
	}
}

void auto_move_if(map_t *map, entity_t *my, sfVector2i *dir, int *tmp)
{
	sfBool t = opaque_get(c_font_get(my->type));

	opaque_get(map->tab[my->x - 1][my->y]) == t ? dir[*tmp].x = -1 : 0;
	opaque_get(map->tab[my->x - 1][my->y]) == t ? *tmp += 1 : 0;
	opaque_get(map->tab[my->x + 1][my->y]) == t ? dir[*tmp].x = 1 : 0;
	opaque_get(map->tab[my->x + 1][my->y]) == t ? *tmp += 1 : 0;
	opaque_get(map->tab[my->x][my->y - 1]) == t ? dir[*tmp].y = -1 : 0;
	opaque_get(map->tab[my->x][my->y - 1]) == t ? *tmp += 1 : 0;
	opaque_get(map->tab[my->x][my->y + 1]) == t ? dir[*tmp].y = 1 : 0;
	opaque_get(map->tab[my->x][my->y + 1]) == t ? *tmp += 1 : 0;
}

void auto_move(map_t *map, entity_t *my)
{
	int tmp = 0;
	int npa;
	sfVector2i dir[4] = {{0, 0}, {0, 0}, {0, 0}, {0, 0}};
	sfBool op = opaque_get(c_font_get(my->type));

	if (op != opaque_get(map->tab[my->x][my->y])) {
		auto_move_if(map, my, dir, &tmp);
		if (tmp > 0) {
			npa = tmp > 0 ? rand() % tmp : 0;
			my->x += dir[npa].x;
			my->y += dir[npa].y;
		}
		else
			my->vie--;
	}
}

void entity_move(map_t *map, entity_t *entity, char play)
{
	int player_id = 0;
	bool vie;

	for (int i = 0; i < nb_entity; i++) {
		if (entity[i].vie > 0 && entity[i].type == 'P') {
			player_move(map, entity, &entity[i], play);
			player_id = i;
			break;
		}
	}
	for (int i = 0; i < nb_entity; i++) {
		vie = entity[i].vie > 0 ? true : false;
		if (vie && map->tab[entity[i].x][entity[i].y] == 'F')
			entity[i].vie--;
		vie ? auto_move(map, &entity[i]) : 0;
		if (vie > 0 && entity[i].type != 'P')
			IA(map, entity, &entity[i], &entity[player_id]);
	}
}
