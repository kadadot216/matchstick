/*
** EPITECH PROJECT, 2018
** structs.h
** File description:
** Header file for Structures definitions
*/

#ifndef __MATCHSTICK_STRUCTS_H__
#define __MATCHSTICK_STRUCTS_H__

#include "stypes.h"

struct	game_board_s {
	char		**display;
	uint_t		*maxsticks_atl;
	uint_t		*remsticks_atl;
	uint_t		max_lines;
	uint_t		max_width;
	board_status_t	status;
};

#endif
