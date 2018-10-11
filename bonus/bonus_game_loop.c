/*
** EPITECH PROJECT, 2018
** bonus_game_loop.c
** File description:
** Modified game_loop for bonus
*/

#include "ai.h"
#include "checking.h"
#include "defs.h"
#include "./include/bonus.h"
#include "messages.h"
#include "my.h"
#include "prototypes.h"
#include "types.h"
#include "update.h"
#include "user_prompt.h"


game_status_t	bonus_play_turn(game_board_t *board, turn_type_t type,
ai_strat_t ai_strategy)
{
	p_choice_t	choice = {0, 0};
	game_status_t	prompt_ok = RUNNING;

	if (type == PLAYER) {
		prompt_ok = get_input_choice(&choice, board);
	} else if (type == AI) {
		ai_strategy(&choice, board);
	}
	if (prompt_ok == EOF_QUIT) {
		return (prompt_ok);
	}
	update_board_with(board, &choice, type);
	return (RUNNING);
}

game_status_t	bonus_play_game(game_board_t *board, int diff_choice)
{
	game_status_t	status = RUNNING;
	turn_type_t	turn_of = 0;
	uint_t	turn = 0;
	ai_strat_t	ai_lvl[] = { &airand_get_input_choice,
		&ai_get_input_choice
	};

	display_board(board);
	while (status == RUNNING) {
		turn_of = (turn % 2);
		display_turn_msg(turn_of);
		status = bonus_play_turn(board, turn_of, ai_lvl[diff_choice]);
		if (status == EOF_QUIT) {
			return (ABORT);
		}
		display_board(board);
		status = check_for_win_condition(board, turn_of);
		turn++;
	}
	print_loss_msg(status);
	return (status);
}
