/*
** EPITECH PROJECT, 2017
** Z-end
** File description:
** IA_b.c
*/

#include <stdlib.h>
#include "prototype.h"

static sfVector2i dir(map_t *map, entity_t *my)
{
    sfVector2i path = {0, 0};

        if (rand() % 2)
                path.x = rand() % 2 * 2 - 1;
        else
                path.y = rand() % 2 * 2 - 1;
        if (opaque_get(map->tab[my->x + path.x][my->y + path.y])) {
                path.x = 0;
                path.y = 0;
        }
        return (path);
}

void IA_b(map_t *map, entity_t *entity, entity_t *my, entity_t *cible)
{
        my->var1++;
        if (my->var1 >= 5) {
                sfVector2i path;

                if (rand() % 2)
                        path = pathfinding(map, my, cible);
                else
                        path = dir(map, my);
                my->var1 = 0;
                my->x += path.x;
                my->y += path.y;
                my->var2++;
                my->var2 >= 12 ? my->vie = 0 : 0;
        }
}
