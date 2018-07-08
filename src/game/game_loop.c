#include "types.h"
#include "prototypes.h"
#include "user_prompt.h"
#include "checking.h"
#include "update.h"
#include "defs.h"

#include "my.h"

void	get_input_choice(p_choice_t *c, game_board_t *b)
{
	c->line = get_line_input(b);
	c->matches = get_matches_input(b, c->line);
}

void	play_turn(game_board_t *board)
{
	p_choice_t	choice = {0, 0};

	get_input_choice(&choice, board);
	update_board_with(board, &choice);
}

int	check_for_win_condition(void)
{
	return (0);
}

void	play_game(game_board_t *board)
{
	game_status_t	status = RUNNING;	
	uint_t	turn = 1;

	while (status == RUNNING) {
		display_board(board);
		if (is_odd(turn)) {
			my_putstr_fd(1, "Your turn:\n");
			play_turn(board);
		} else {
			my_putstr_fd(1, "AI's turn...\n");
			play_turn(board);
		}
		check_for_win_condition();
		turn++;
	}
}
