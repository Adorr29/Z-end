/*
** EPITECH PROJECT, 2017
** Z-end
** File description:
** liens_texture.h
*/

#ifndef LIENS_TEXTURE_H_
#define LIENS_TEXTURE_H_

typedef struct
{
	char c;
	char c_font;
	char *file_font_name;
	char *file_name;
} liens_texture_t;

char c_font_get(char c);
char *file_font_name_get(char c);
char *file_name_get(char c);

#endif
