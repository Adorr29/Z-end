/*
** EPITECH PROJECT, 2017
** Z-end
** File description:
** file_font_name_get.c
*/

#include "liens_texture.h"
#include "liens_tex.h"

char *file_font_name_get(char c)
{
	for (int i = 0; liens_tex[i].c != '\0'; i++) {
		if (liens_tex[i].c == c)
			return (liens_tex[i].file_font_name);
	}
	return (NULL);
}
