/*
** EPITECH PROJECT, 2018
** prototypes.h
** File description:
** Header file for function prototypes
*/

#ifndef __MATCHSTICK_PROTO_H__
#define __MATCHSTICK_PROTO_H__

#include "types.h"

game_board_t	*init_board(int nb_lines, int max_sticks);
game_board_t	*unset_board(game_board_t *board);
void	display_board(game_board_t *board);
void	play_game(game_board_t *board);

#endif
