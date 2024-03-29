#ifndef __MATCHSTICK_STRUCTS_H__
#define __MATCHSTICK_STRUCTS_H__

#include "stypes.h"

struct	game_board_s {
	char	**display;
	uint_t	*remmatches_atl;
	uint_t	match_limit;
	uint_t	max_lines;
	uint_t	max_width;
	board_status_t	status;
};

struct	p_choice_s {
	int	line;
	int	matches;
};

#endif
