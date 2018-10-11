#ifndef __MATCHSTICK_PROTO_H__
#define __MATCHSTICK_PROTO_H__

#include "types.h"

void	display_board(game_board_t *board);
void	print_help_msg(char *pname);
game_status_t	play_game(game_board_t *board);
game_board_t	*init_board(int nb_lines, int max_sticks);
game_board_t	*unset_board(game_board_t *board);

#endif
