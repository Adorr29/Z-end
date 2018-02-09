/*
** EPITECH PROJECT, 2017
** Z-end
** File description:
** prototype.h
*/

#ifndef PROTOTYPE_H_
#define PROTOTYPE_H_

#include "map.h"
#include "entity.h"

int game(sfRenderWindow *window, map_t *map);
char play_get(sfRenderWindow *window);
bool opaque_get(char c);
int win_get(map_t *map, entity_t *entity);
void entity_move(map_t *map, entity_t *entity, char play);
void aff(sfRenderWindow *window, sfVector2f pos, char *file_name);
sfVector2i move_rand(map_t *map, entity_t *my);
sfVector2i pathfinding(map_t *map, entity_t *my, entity_t *cible);
void IA_E(map_t *map, entity_t *entity, entity_t *my, entity_t *cible);
void IA_T(map_t *map, entity_t *entity, entity_t *my, entity_t *cible);
void IA_D(map_t *map, entity_t *entity, entity_t *my, entity_t *cible);
void IA_d(map_t *map, entity_t *entity, entity_t *my, entity_t *cible);
void IA_B(map_t *map, entity_t *entity, entity_t *my, entity_t *cible);
void IA_b(map_t *map, entity_t *entity, entity_t *my, entity_t *cible);
void IA_K(map_t *map, entity_t *entity, entity_t *my, entity_t *cible);
void IA_0(map_t *map, entity_t *entity, entity_t *my, entity_t *cible);
void IA_1(map_t *map, entity_t *entity, entity_t *my, entity_t *cible);
void IA_2(map_t *map, entity_t *entity, entity_t *my, entity_t *cible);
void IA_3(map_t *map, entity_t *entity, entity_t *my, entity_t *cible);
void IA_4(map_t *map, entity_t *entity, entity_t *my, entity_t *cible);

#endif
