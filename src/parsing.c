/*
** EPITECH PROJECT, 2018
** parsing.c
** File description:
** Parsing file
*/

#include <stdlib.h>
#include "defs.h"
#include "my.h"

int	parse_value(char *arg)
{
	int	value = -1;

	if (arg == NULL || !my_str_isnum(arg)) {
		return (-1);
	} else {
		value = my_getnbr(arg);
	}
	return (value);
}
