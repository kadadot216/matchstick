#ifndef __MATCHSTICK_VALUE_CHECKS_H__
#define __MATCHSTICK_VALUE_CHECKS_H__

#include "stypes.h"

void	check_for_invalid_prompt(int *value);
int	line_is_valid(int value, uint_t max_lines);
int	matches_are_valid(int value, uint_t remmatches, uint_t limit);

#endif
