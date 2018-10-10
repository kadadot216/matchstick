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
#include "messages.h"
#include "ai.h"
#include "my.h"

void	get_input_choice(p_choice_t *c, game_board_t *b)
{
	while (c->matches <= 0) {
		c->line = get_line_input(b);
		c->matches = get_matches_input(b, c->line);
	}
}

void	play_turn(game_board_t *board, turn_type_t type, int ai_lvl)
{
	p_choice_t	choice = {0, 0};

	if (type == PLAYER) {
		get_input_choice(&choice, board);
	} else if (type == AI) {
		ai_get_input_choice(&choice, board, ai_lvl);
	}
	update_board_with(board, &choice, type);
}

game_status_t	check_for_win_condition(game_board_t *board, uint_t turn)
{
	uint_t	i = 0;

	while (i < board->max_lines) {
		if (board->remmatches_atl[i] != 0) {
			return (RUNNING);
		}
		i++;
	}
	if (is_odd(turn)) {
		return (AI_WON);
	} else if (!is_odd(turn)) {
		return (PLAYER_WON);
	}
	return (RUNNING);
}

game_status_t	play_game(game_board_t *board)
{
	game_status_t	status = RUNNING;	
	uint_t	turn = 1;
	int	ai_lvl = 0;

	ai_lvl = rand_iv(0, 1);
	while (status == RUNNING) {
		display_board(board);
		if (is_odd(turn)) {
			my_putstr_fd(1, "Your turn:\n");
			play_turn(board, PLAYER, ai_lvl);
		} else {
			my_putstr_fd(1, "AI's turn...\n");
			play_turn(board, AI, ai_lvl);
		}
		status = check_for_win_condition(board, turn);
		turn++;
	}
	print_loss_msg(status);
	return (status);
}
