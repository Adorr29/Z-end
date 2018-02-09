/*
** EPITECH PROJECT, 2017
** Z-end
** File description:
** liens_tex.h
*/

#ifndef LIENS_TEX_H_
#define LIENS_TEX_H_

#include <stdlib.h>

static liens_texture_t liens_tex[] = {
	{'#', '\0', NULL, "texture/wall.png"},
	{'.', '\0', NULL, "texture/ground.png"},
	{'+', '.', "texture/ground.png", "texture/box.png"},
	{'f', '.', "texture/ground.png", "texture/fire1.png"},
	{'F', '.', "texture/ground.png", "texture/fire2.png"},
	{'m', '\0', NULL, "texture/ground.png"},
	{'M', '\0', NULL, "texture/wall.png"},
	{'S', '.', "texture/ground.png", "texture/exit.png"},
	{'P', '.', "texture/ground.png", "texture/player.png"},
	{'p', '.', "texture/ground.png", "texture/trap.png"},
	{'E', '.', "texture/ground.png", "texture/enemy_E.png"},
	{'T', '.', "texture/ground.png", "texture/enemy_T.png"},
	{'D', '.', "texture/ground.png", "texture/enemy_D.png"},
	{'d', '.', "texture/ground.png", "texture/enemy_d.png"},
	{'B', '.', "texture/ground.png", "texture/enemy_B.png"},
	{'b', '.', "texture/ground.png", "texture/enemy_b.png"},
	{'K', '#', "texture/wall.png", "texture/enemy_K.png"},
	{'1', '.', "texture/ground.png", "texture/enemy_1.png"},
	{'2', '.', "texture/ground.png", "texture/enemy_2.png"},
	{'3', '.', "texture/ground.png", "texture/enemy_3.png"},
	{'4', '.', "texture/ground.png", "texture/enemy_4.png"},
	{'9', '.', "texture/ground.png", "texture/enemy_9.png"},
	{'\0', '\0', NULL, NULL}
};

#endif
