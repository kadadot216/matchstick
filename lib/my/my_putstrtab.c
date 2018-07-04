/*
** EPITECH PROJECT, 2018
** my_putstrtab.c
** File description:
** Displays the contents of an array of words
*/

#include "my.h"

void	my_putstrtab(char **tab)
{
	int	i = 0;

	while (tab[i] != 0) {
		my_putstr(tab[i]);
		my_putchar('\n');
		i++;
	}
}
