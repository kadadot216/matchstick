/*
** EPITECH PROJECT, 2018
** my_putcharx.c
** File description:
** Displays the same character c times times
*/

#include <unistd.h>

void	my_putcharx(char c, int times)
{
	int	i = 0;
	while (i < times) {
		write(1, &c, 1);
		i++;
	}
}
