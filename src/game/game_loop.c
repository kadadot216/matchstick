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
	my_putstr_fd(2, "Error: you cannot remove more than ");
	my_put_nbr_fd(2, upper_bound);
	my_putstr_fd(2, " matches per turn\n");
}

void	print_error_line_oor(void)
{
	my_putstr_fd(2, "Error: this line is out of range\n");
}

void	print_error_no_sticks(void)
{
	my_putstr_fd(2, "Error: you have to remove at least one match\n");
}

void	print_error_not_enough_sticks(void)
{
	my_putstr_fd(2, "Error: not enough matches on this line\n");
}
//

void	get_input_choice(p_choice_t *c, game_board_t *b)
{
	c->line = (get_input("Line: ", b->max_lines,
		print_error_line_oor) - 1);
	if (b->remsticks_atl[c->line] > 0) {
	c->nbsticks = get_input("Stick: ", b->stick_limit,
			print_error_sticks_oob);
	}
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
			my_putstr_fd(1, "Your turn:\n");
			play_turn(board);
		} else {
			my_putstr_fd(1, "AI's turn...\n");
			play_turn(board);
		}
		check_for_win_condition();
		turn++;
	}
}
