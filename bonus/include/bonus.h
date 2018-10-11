/*
** EPITECH PROJECT, 2018
** game.h
** File description:
** Header file for game_loop.c
*/

#ifndef __GAME_H__
#define __GAME_H__

#include "types.h"

typedef void	(*ai_strat_t)(p_choice_t *, game_board_t *);

int	random_iv(int min, int max);
game_status_t	bonus_play_game(game_board_t *board, int diff_choice);
game_status_t	check_for_win_condition(game_board_t *board, turn_type_t tt);
game_status_t	play_turn(game_board_t *board, turn_type_t type);
game_status_t	get_input_choice(p_choice_t *c, game_board_t *b);
void	airand_get_input_choice(p_choice_t *c, game_board_t *b);
int	select_ai_lvl(char *arg);


#endif /* __GAME_H__ */
