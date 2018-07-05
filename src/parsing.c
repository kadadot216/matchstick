/*
** EPITECH PROJECT, 2018
** parsing.c
** File description:
** Parsing file
*/

#include <stdlib.h>
#include "defs.h"
#include "my.h"

int	parse_nb_lines(char **av)
{
	char	*arg = NULL;
	int	nb_lines = 0;

	if (av[1] == NULL) {
		nb_lines = NB_LINES_DEFAULT;
	} else {
		arg = av[1];
		nb_lines = my_getnbr(arg);
	}
	return (nb_lines);
}
