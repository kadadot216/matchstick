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
	while (c->matches == 0 || c->matches == -1) {
		c->line = get_line_input(b);
		c->line--;
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

int	is_board_clear(game_board_t *board)
{
	uint_t	i = 0;

	while (i < board->max_lines) {
		if (board->remmatches_atl[i] != 0) {
			return (0);
		}
		i++;
	}
	return (1);
}

game_status_t	check_for_win_condition(game_board_t *board, turn_type_t tt)
{
	if (is_board_clear(board) && tt == PLAYER) {
		return (AI_WON);
	} else if (is_board_clear(board) && tt == AI) {
		return (PLAYER_WON);
	}
	return (RUNNING);
}

void	display_turn_msg(turn_type_t tt)
{
	if (tt == PLAYER)
		my_putstr_fd(1, "\nYour turn:\n");
	else if (tt == AI)
		my_putstr_fd(1, "\nAI's turn...\n");
}

game_status_t	play_game(game_board_t *board)
{
	game_status_t	status = RUNNING;	
	turn_type_t	turn_of = 0;
	uint_t	turn = 0;
	int	ai_lvl = 0;

	ai_lvl = rand_iv(0, 1);
	display_board(board);
	while (status == RUNNING) {
		turn_of = (turn % 2);
		display_turn_msg(turn_of);
		play_turn(board, turn_of, ai_lvl);
		display_board(board);
		status = check_for_win_condition(board, turn_of);
		turn++;
	}
	print_loss_msg(status);
	return (status);
}
