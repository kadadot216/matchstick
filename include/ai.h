/*
** EPITECH PROJECT, 2018
** ai.h
** File description:
** Header file for ai.c
*/

#ifndef __MATCHSTICK_AI_H__
#define __MATCHSTICK_AI_H__

#include "types.h"

void	ai_get_input_choice(p_choice_t *choice, game_board_t *board,
int ai_lvl);
int	rand_iv(int min, int max);

#endif

