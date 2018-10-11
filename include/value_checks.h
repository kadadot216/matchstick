#ifndef __MATCHSTICK_VALUE_CHECKS_H__
#define __MATCHSTICK_VALUE_CHECKS_H__

#include "types.h"

void	check_for_invalid_prompt(int *value);
int	line_is_valid(int value, uint_t max_lines);
int	matches_are_valid(int value, uint_t remmatches, uint_t limit);
int	check_for_last_line(game_board_t *b);

#endif
