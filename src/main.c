/*
** EPITECH PROJECT, 2017
** Z-end
** File description:
** main.c
*/

#include <stdio.h>
#include <stdlib.h>
#include "prototype.h"
#include "nb_level.h"

void time_aff(sfClock *time)
{
	int sec;
	int min;

	sec = sfClock_getElapsedTime(time).microseconds;
	sec /= 1000000;
	for (min = 0; sec >= 60; sec -= 60)
		min++;
	printf("%.2d:%.2d\n", min, sec);
}

sfRenderWindow *window_create()
{
	sfVideoMode mode = {1920, 1080, 32};
	sfRenderWindow *window;

	window = sfRenderWindow_create(mode, "Z-end", sfFullscreen, NULL);
	sfRenderWindow_setFramerateLimit(window, 30);
	sfRenderWindow_setMouseCursorVisible(window, sfFalse);
	srand((long long)window);
	return (window);
}

void main_destroy(sfRenderWindow *window, sfClock *gm_time, sfClock *lvl_time)
{
	printf("temps totale : ");
	time_aff(gm_time);
	sfClock_destroy(gm_time);
	sfClock_destroy(lvl_time);
	sfRenderWindow_destroy(window);
}

void game_manage(sfRenderWindow *window, int *level, sfClock *level_time)
{
	char *map_name = malloc(sizeof(char) * 30);
	map_t map;
	int win;

	sfClock_restart(level_time);
	sprintf(map_name, "maps/level%d", *level);
	map = map_create_from_file(map_name);
	win = game(window, &map);
	win > 0 ? printf("temps niveau %d : ", *level) : 0;
	win > 0 ? time_aff(level_time) : 0;
	*level + win > 0 ? *level += win : ((*level) = 1);
	*level > nb_level ? sfRenderWindow_close(window) : 0;
	map_destroy(&map);
	free(map_name);
}

void main(void)
{
	sfRenderWindow *window = window_create();
	sfClock *game_time = sfClock_create();
	sfClock *level_time = sfClock_create();
	int level = 1;

	while (sfRenderWindow_isOpen(window))
		game_manage(window, &level, level_time);
	main_destroy(window, game_time, level_time);
}
