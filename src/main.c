#include <stdlib.h>
#include "my.h"
#include "prototypes.h"
#include "types.h"
#include "parsing.h"

int	main(int ac, char **av)
{
	game_board_t	*board = NULL;
	int	nb_lines = 0;
	int	match_limit = 0;

	if (ac > 3 || ac < 3) {
		return (84);
	}
	nb_lines = parse_value(av[1]);
	match_limit = parse_value(av[2]);
	if (nb_lines == -1 || match_limit == -1) {
		return (84);
	}
	board = init_board(nb_lines, match_limit);
	if (board == NULL || board->status == ERROR) {
		return (84);
	}
	play_game(board);
	board = unset_board(board);
	return (0);
}
