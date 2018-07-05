/*
** EPITECH PROJECT, 2018
** game_loop.c
** File description:
** Game loop routine
*/

#include "types.h"
#include "prototypes.h"
#include "user_prompt.h"
#include "checking.h"
#include "update.h"


void	play_turn(game_board_t *b)
{
	uint_t	sel_line = 0;
	uint_t	sel_nbsticks = 0;

	while (sel_nbsticks == 0) {
		sel_line = (get_input("Line: ", b->max_lines) - 1);
		sel_nbsticks = get_input("Stick: ", b->remsticks_atl[sel_line]);
	}

	update_board_with(b, sel_line, sel_nbsticks);
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
