/*
** EPITECH PROJECT, 2017
** Z-end
** File description:
** IA_B.c
*/

#include <stdlib.h>
#include "prototype.h"

static void IA_B2(map_t *map, entity_t *entity, entity_t *my, entity_t *cible)
{
        if (my->var1 >= 50) {
                sfVector2i path = pathfinding(map, my, cible);

                my->var1 = 0;
                if (path.x == 0 && path.y == 0)
                        path = move_rand(map, my);
                my->x += path.x;
                my->y += path.y;
        }
}

void IA_B(map_t *map, entity_t *entity, entity_t *my, entity_t *cible)
{
        my->var1++;
        if (abs(my->x - cible->x) + abs(my->y - cible->y) > 10)
                IA_B2(map, entity, my, cible);
        else if (my->var1 >= 10) {
                my->var1 = 0;
                entity_set_up(entity, my->x, my->y, 'b');
        }
}
