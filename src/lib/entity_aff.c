/*
** EPITECH PROJECT, 2017
** Z-end
** File description:
** entity_aff.c
*/

#include "prototype.h"
#include "entity.h"
#include "health_bar.h"
#include "liens_texture.h"
#include "case_size.h"
#include "nb_entity.h"

void manage_rect_var(entity_t *entity)
{
	rect_var1 /= -2;
	rect_var2 > entity->vie ? rect_var2 -= 0.1 : 0;
}

void rect_aff(sfRenderWindow *window, entity_t *entity, sfFloatRect *r, float m)
{
	sfRectangleShape *rect1 = sfRectangleShape_create();
	sfRectangleShape *rect2 = sfRectangleShape_create();
	sfVector2u win_size = sfRenderWindow_getSize(window);
	sfVector2f pos = {r->left + rect_left * m, r->top + rect_top * m};
	sfVector2f size1 = {rect_width * m / 10 * entity->vie, rect_height * m};
	sfVector2f size2 = {rect_width * m / 10 * rect_var2, rect_height * m};
	sfColor color = entity->vie > 3 ? sfGreen : sfYellow;

	pos.y += rect_var1;
	sfRectangleShape_setFillColor(rect1, color);
	sfRectangleShape_setPosition(rect1, pos);
	sfRectangleShape_setSize(rect1, size1);
	sfRectangleShape_setFillColor(rect2, sfRed);
	sfRectangleShape_setPosition(rect2, pos);
	sfRectangleShape_setSize(rect2, size2);
	sfRenderWindow_drawRectangleShape(window, rect2, NULL);
	sfRenderWindow_drawRectangleShape(window, rect1, NULL);
	manage_rect_var(entity);
	sfRectangleShape_destroy(rect1);
	sfRectangleShape_destroy(rect2);
}

void set_origin_on_middle(sfSprite *sprite, sfFloatRect rect)
{
	sfVector2f middle;

	middle.x = rect.width / 2;
	middle.y = rect.height / 2;
	sfSprite_setOrigin(sprite, middle);
}

void hp_aff(sfRenderWindow *window, entity_t *entity)
{
	sfTexture *texture = sfTexture_createFromFile(health_bar, NULL);
	sfSprite *sprite = sfSprite_create();
	sfFloatRect rect;
	sfVector2f scale;
	sfVector2u win_size = sfRenderWindow_getSize(window);
	sfVector2f pos = {win_size.x / 2, win_size.y / 45 + rect_var1};

	sfSprite_setTexture(sprite, texture, sfTrue);
	rect = sfSprite_getLocalBounds(sprite);
	set_origin_on_middle(sprite, rect);
	scale.x = (win_size.x / 10) / rect.width;
	scale.y = scale.x;
	sfSprite_scale(sprite, scale);
	sfSprite_setPosition(sprite, pos);
	sfRenderWindow_drawSprite(window, sprite, NULL);
	rect = sfSprite_getGlobalBounds(sprite);
	rect_aff(window, entity, &rect, scale.x);
	sfTexture_destroy(texture);
	sfSprite_destroy(sprite);
}

void entity_aff(sfRenderWindow *window, map_t *map, entity_t *entity)
{
	sfVector2u win_size = sfRenderWindow_getSize(window);
	sfVector2f pos;
	char t;

	for (int i = 0; i < nb_entity; i++) {
		t = entity[i].type;
		if (entity[i].vie > 0) {
			pos.x = entity[i].x * CASE_SIZE;
			pos.x += CASE_SIZE / 2 + win_size.x / 2;
			pos.x -= map->nb_case_x * CASE_SIZE / 2;
			pos.y = entity[i].y * CASE_SIZE;
			pos.y += CASE_SIZE / 2 + win_size.y / 2;
			pos.y -= map->nb_case_y * CASE_SIZE / 2;
			aff(window, pos, file_name_get(entity[i].type));
		}
		t > '0' && t < '9' ? hp_aff(window, &entity[i]) : 0;
	}
}
