/*
** EPITECH PROJECT, 2017
** Z-end
** File description:
** c_font_get.c
*/

#include "liens_texture.h"
#include "liens_tex.h"

char c_font_get(char c)
{
	for (int i = 0; liens_tex[i].c != '\0'; i++) {
		if (liens_tex[i].c == c)
			return (liens_tex[i].c_font);
	}
	return ('\0');
}
