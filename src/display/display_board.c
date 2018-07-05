/*
** EPITECH PROJECT, 2018
** display_board.c
** File description:
** Displays the matchstick boards
*/

#include <stdlib.h>
#include "types.h"
#include "my.h"

int	display_board(game_board_t *board)
{
	uint_t	j = 0;

	if (board == NULL) {
		return (-1);
	}
	my_putcharx('*', (board->max_width + 2));
	my_putchar('\n');
	while (j < board->max_lines) {
		my_putchar('*');
		my_putstr(board->display[j]);
		my_putchar('*');
		my_putchar('\n');
		j++;
	}
	my_putcharx('*', (board->max_width + 2));
	my_putchar('\n');
	return (0);
}
