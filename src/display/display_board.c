/*
** EPITECH PROJECT, 2018
** display_board.c
** File description:
** Displays the matchstick boards
*/

#include "my.h"

void	display_board(char **board, int height, int width)
{
	int	i = 0;

	my_putcharx('*', (width + 2));
	my_putchar('\n');
	while (i < height) {
		my_putchar('*');
		my_putstr(board[i]);
		my_putchar('*');
		my_putchar('\n');
		i++;
	}
	my_putcharx('*', (width + 2));
	my_putchar('\n');
}
