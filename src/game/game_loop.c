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
#include "defs.h"

#include "my.h"

void	print_error_sticks_oob(int upper_bound)
{
	my_putstr("Error: you cannot remove more than ");
	my_put_nbr(upper_bound);
	my_putstr(" matches per turn\n");
}

void	print_error_line_oor(void)
{
	my_putstr("Error: this line is out of range\n");
}

//

void	get_input_choice(p_choice_t *c, game_board_t *b)
{
	c->line = (get_input("Line: ", b->max_lines,
		print_error_line_oor) - 1);
	c->nbsticks = get_input("Stick: ", b->remsticks_atl[c->line],
			print_error_sticks_oob);
}

void	play_turn(game_board_t *board)
{
	p_choice_t	choice = {0, 0};

	while (choice.nbsticks == 0) {
		get_input_choice(&choice, board);
	}
	update_board_with(board, &choice);
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
