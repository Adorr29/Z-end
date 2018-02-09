/*
** EPITECH PROJECT, 2017
** Z-end
** File description:
** play_get.c
*/

#include "prototype.h"

char how_key2()
{
	if (sfKeyboard_isKeyPressed(sfKeyQ))
		return ('L');
	if (sfKeyboard_isKeyPressed(sfKeyA))
		return ('L');
	if (sfKeyboard_isKeyPressed(sfKeyD))
		return ('R');
	if (sfKeyboard_isKeyPressed(sfKeyE))
		return ('R');
	if (sfKeyboard_isKeyPressed(sfKeyZ))
		return ('U');
	if (sfKeyboard_isKeyPressed(sfKeyS))
		return ('D');
	return (0);
}

char how_key()
{
	if (sfKeyboard_isKeyPressed(sfKeyLeft))
		return ('L');
	if (sfKeyboard_isKeyPressed(sfKeyRight))
		return ('R');
	if (sfKeyboard_isKeyPressed(sfKeyUp))
		return ('U');
	if (sfKeyboard_isKeyPressed(sfKeyDown))
		return ('D');
	if (sfKeyboard_isKeyPressed(sfKeySpace))
		return (' ');
	return (how_key2());
}

char play_get(sfRenderWindow *window)
{
	sfEvent event;

	while (sfRenderWindow_pollEvent(window, &event)) {
		if (event.type == sfEvtClosed)
			sfRenderWindow_close(window);
		else if (event.type == sfEvtKeyPressed)
			return (how_key());
	}
	return (0);
}
