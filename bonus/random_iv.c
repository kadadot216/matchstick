/*
** EPITECH PROJECT, 2018
** random_iv.c
** File description:
** Get a random number between min/max.
*/

#include <stdlib.h>

int	random_iv(int min, int max)
{
	int	diff = ((max + 1) - min);

	return (min + (random() % diff));
}
