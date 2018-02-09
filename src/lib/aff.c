/*
** EPITECH PROJECT, 2017
** Z-end
** File description:
** aff.c
*/

#include <SFML/Graphics.h>
#include "case_size.h"

void aff(sfRenderWindow *window, sfVector2f pos, char *file_name)
{
	sfTexture *texture = sfTexture_createFromFile(file_name, NULL);
	sfSprite *sprite = sfSprite_create();
	sfVector2f scale;
	sfVector2f middle;
	sfFloatRect rect;

	sfSprite_setTexture(sprite, texture, sfTrue);
	rect = sfSprite_getLocalBounds(sprite);
	scale.x = CASE_SIZE / rect.width;
	scale.y = CASE_SIZE / rect.height;
	middle.x = rect.width / 2;
	middle.y = rect.height / 2;
	sfSprite_scale(sprite, scale);
	sfSprite_setOrigin(sprite, middle);
	sfSprite_setPosition(sprite, pos);
	sfSprite_setRotation(sprite, 0);
	sfRenderWindow_drawSprite(window, sprite, NULL);
	sfTexture_destroy(texture);
	sfSprite_destroy(sprite);
}
