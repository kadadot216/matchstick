#include <stdlib.h>
#include "my.h"
#include "prototypes.h"
#include "types.h"
#include "parsing.h"

int	main(int ac, char **av)
{
	game_board_t	*board = NULL;
	game_status_t	status = 0;
	int	nb_lines = 0;
	int	match_limit = 0;

	if (ac > 3 || ac < 3) {
		print_help_msg(av[0]);
		return (84);
	}
	nb_lines = parse_value(av[1]);
	match_limit = parse_value(av[2]);
	board = init_board(nb_lines, match_limit);
	if (board == NULL || board->status == ERROR) {
		return (84);
	}
	status = play_game(board);
	board = unset_board(board);
	return (status);
}
