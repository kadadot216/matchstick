/*
** EPITECH PROJECT, 2018
** player_move.c
** File description:
** UT For first player move
*/

#include "unit_testing.h"
#include "structs.h"
#include "prototypes.h"
#include "test_update_board.h"

void	test_update_board(game_board_t *b, p_choice_t *c)
{
	remove_sticks(&b->remmatches_atl[c->line], &c->matches);
	remove_from_display(b, c);
}

Test(player_move, select2from2, .init=redirect_all_std)
{
	game_board_t	*board = init_board(4, 2);
	p_choice_t	choice = {1, 2};
	char	*buffer =
		"*********\n"
		"*   |   *\n"
		"*  |    *\n"
		"* ||||| *\n"
		"*|||||||*\n"
		"*********\n\n";

	cr_assert_eq(board->remmatches_atl[choice.line], 3);
	test_update_board(board, &choice);
	cr_assert_eq(board->remmatches_atl[choice.line], 1);
	fflush(stdout);
	display_board(board);
	board = unset_board(board);
	cr_assert_stdout_eq_str(buffer, "");
}

void	player_move_multiple_plays(game_board_t *b, p_choice_t *c)
{
	cr_assert_eq(b->remmatches_atl[c->line], 3);
	test_update_board(b, c);
	cr_assert_eq(b->remmatches_atl[c->line], 1);
	*c = (p_choice_t) {1, 1};
	test_update_board(b, c);
	cr_assert_eq(b->remmatches_atl[c->line], 0);
	*c = (p_choice_t) {2, 2};
	test_update_board(b, c);
	cr_assert_eq(b->remmatches_atl[c->line], 3);
	*c = (p_choice_t) {2, 1};
	test_update_board(b, c);
	cr_assert_eq(b->remmatches_atl[c->line], 2);
}

Test(player_move, multiple_plays, .init=redirect_all_std)
{
	game_board_t	*board = init_board(4, 2);
	p_choice_t	choice = {(2 - 1), 2};
	char	*buffer =
		"*********\n"
		"*   |   *\n"
		"*       *\n"
		"* ||    *\n"
		"*|||||||*\n"
		"*********\n\n";

	player_move_multiple_plays(board, &choice);
	fflush(stdout);
	display_board(board);
	board = unset_board(board);
	cr_assert_stdout_eq_str(buffer, "");
}
