/*
** EPITECH PROJECT, 2018
** my_put_nbr.c
** File description:
** Displays the number given as a parameter.
*/

#include "my.h"

int	my_put_nbr(int nb)
{
	if (nb < 0) {
		my_putchar('-');
		nb = -nb;
	}
	if (nb / 10)
		my_put_nbr(nb / 10);
	my_putchar(nb % 10 + '0');
	return (0);
}

