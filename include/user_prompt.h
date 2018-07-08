/*
** EPITECH PROJECT, 2018
** user_prompt.h
** File description:
** Header file for user's prompt function prototypes
*/

#ifndef __MATCHSTICK_USER_PROMPT_H__
#define __MATCHSTICK_USER_PROMPT_H__

#include "types.h"

int	get_line_input(game_board_t *board);
int	get_matches_input(game_board_t *board, uint_t line);
int	ask_number(void);

#endif
