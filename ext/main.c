#include <stdlib.h>
#include "my.h"
#include "prototypes.h"
#include "types.h"
#include "parsing.h"
#include "./include/ext.h"
#include <time.h>

int	main(int ac, char **av)
{
	game_board_t	*board = NULL;
	game_status_t	status = 0;
	int	ai_lvl = 0;

	srandom(time(NULL));
	if (ac > 4 || ac < 3) {
		ext_print_help_msg(av[0]);
		return (84);
	}
	ai_lvl = parse_difficulty(av[3]);
	ext_print_seldiff(ai_lvl);
	board = init_board(parse_value(av[1]), parse_value(av[2]));
	if (board == NULL || board->status == ERROR) {
		return (84);
	}
	status = ext_play_game(board, ai_lvl);
	board = unset_board(board);
	return (status);
}

