/*
** EPITECH PROJECT, 2018
** game_loop.c
** File description:
** Game loop routine
*/

#include "types.h"
#include "prototypes.h"

#include <stdlib.h>
#include "my.h"

int	is_odd(uint_t n)
{
	return (n % 2);
}

uint_t	set_prompt_value(char const *prompt, uint_t up_lim)
{
	int	value = my_getnbr(prompt);

	if (value > up_lim || value <= 0) {
		my_putstr("Value is out of bounds.\n");
		return (0);
	} else {
		return (value);
	}
}

int	prompt_is_nb(char const *prompt)
{
	if (!my_str_isnum(prompt)) {
		my_putstr("Invalid input, please try again.\n");
		return (0);
	} else {
		return (1);
	}
}

uint_t	get_input(char *msg, uint_t upper_limit)
{
	char	*prompt = NULL;
	int	value = 0;

	while (value == 0) {
		my_putstr(msg);
		prompt = get_next_line(0);
		if (prompt_is_nb(prompt)) {
			value = set_prompt_value(prompt, upper_limit);
		}
		free(prompt);
		prompt = NULL;
	}
	return (value);
}

void	play_turn(game_board_t *b)
{
	int	sel_line = 0;
	int	sel_nbsticks = 0;

	sel_line = (get_input("Line: ", b->max_lines) - 1);
	sel_nbsticks = get_input("Stick: ", b->maxsticks_atl[sel_line]);

	my_putstr("Line Selected: ");
	my_put_nbr(sel_line+1);
	my_putstr("\n");
	my_putstr("Number of sticks: ");
	my_put_nbr(sel_nbsticks);
	my_putstr("\n");
}

int	check_for_win_condition(void)
{
	return (0);
}

void	play_game(game_board_t *board)
{
	game_status_t	status = RUNNING;	
	uint_t	turn = 1;

	while (status == RUNNING) {
		display_board(board);
		if (is_odd(turn)) {
			play_turn(board);
		} else {
			play_turn(board);
		}
		check_for_win_condition();
		turn++;
	}
}
