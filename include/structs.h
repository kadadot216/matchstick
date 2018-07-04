/*
** EPITECH PROJECT, 2018
** structs.h
** File description:
** Header file for Structures definitions
*/

#ifndef __MATCHSTICK_STRUCTS_H__
#define __MATCHSTICK_STRUCTS_H__

struct	game_board_s {
	unsigned int	total_sticks;
	unsigned int	max_lines;
	unsigned int	*msticks_atl;
	unsigned int	*rsticks_atl;
	char	**display;
};

#endif
