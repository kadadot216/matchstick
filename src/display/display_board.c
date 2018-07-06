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
	my_putcharx_fd(1, '*', (board->max_width + 2));
	my_putchar_fd(1, '\n');
	while (j < board->max_lines) {
		my_putchar_fd(1, '*');
		my_putstr_fd(1, board->display[j]);
		my_putchar_fd(1, '*');
		my_putchar_fd(1, '\n');
		j++;
	}
	my_putcharx_fd(1, '*', (board->max_width + 2));
	my_putstr_fd(1, "\n\n");
	return (0);
}
