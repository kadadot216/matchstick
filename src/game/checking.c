/*
** EPITECH PROJECT, 2018
** checking.c
** File description:
** Checking related functions for game's logic
*/

#include "stypes.h"
#include <stdlib.h>

int	is_odd(uint_t n)
{
	return (n % 2);
}

int	random_iv(int min, int max)
{
	int	q = ((max + 1) - min);

	return (min + (random() % q));
}

int	int_lowest(int val1, int val2)
{
	return ((val1 < val2) ? val1 : val2);
}
