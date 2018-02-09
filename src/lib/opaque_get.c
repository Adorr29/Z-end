/*
** EPITECH PROJECT, 2017
** Z-end
** File description:
** opaque_get.c
*/

#include <stdbool.h>
#include "opaque_block.h"

bool opaque_get(char c)
{
	for (int i = 0; opaque_block[i] != '\0'; i++) {
		if (opaque_block[i] == c)
			return (true);
	}
	return (false);
}
