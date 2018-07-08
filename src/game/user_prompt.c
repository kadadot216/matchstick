/*
** EPITECH PROJECT, 2018
** user_prompt.c
** File description:
** Player's prompt related functions
*/

#include <stdlib.h>
#include "types.h"
#include "my.h"
#include "error_fcts.h"
#include "value_checks.h"

static int	get_valid_prompt(char *msg)
{
	int	value = 0;
	char	*prompt = NULL;

	while (prompt == NULL) {
		my_putstr_fd(1, msg);
		prompt = get_next_line(0);
		if (!my_str_isnum(prompt)) {
			print_error_invalid_prompt();
			free(prompt);
			prompt = NULL;
		}
	}
	value = my_getnbr(prompt);
	free(prompt);
	prompt = NULL;
	return (value);
}

int	get_line_input(game_board_t *board)
{
	int	value = 0;

	while (value <= 0) {
		value = get_valid_prompt("Line: ");
		value = line_is_valid(value, board->max_lines);
	}
	return ((value - 1));
}

int	get_matches_input(game_board_t *board, uint_t line)
{
	int	value = 0;

	while (value == 0) {
		value = get_valid_prompt("Matches: ");
		value = matches_are_valid(value, board->remmatches_atl[line],
			board->match_limit);
	}
	return (value);
}
