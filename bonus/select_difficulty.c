/*
** EPITECH PROJECT, 2018
** select_difficulty.c
** File description:
** Difficulty selection functions
*/

#include "./include/bonus.h"
#include "parsing.h"

#include <stdio.h>

int	set_random_difficulty(void)
{
	return (random_iv(0, 1));
}

int	select_ai_lvl(char *arg)
{
	int	value = parse_value(arg);

	if (value == -1 || value > 1) {
		value = set_random_difficulty();
		printf("AI DIFFICULTY IS: %d\n", value);
		return (value);
	}
	else {
		printf("AI DIFFICULTY IS: %d\n", value);
		return (value);
	}
}
