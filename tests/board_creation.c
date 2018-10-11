/*
** EPITECH PROJECT, 2018
** board_creation.c
** File description:
** UT for testing board creation and display
*/

#include "unit_testing.h"
#include "structs.h"
#include "prototypes.h"

Test(init_board, board_creation1, .init=redirect_all_std)
{
	game_board_t	*board = init_board(4, 2);
	char	*buffer =
		"*********\n"
		"*   |   *\n"
		"*  |||  *\n"
		"* ||||| *\n"
		"*|||||||*\n"
		"*********\n\n";

	fflush(stdout);
	display_board(board);
	board = unset_board(board);
	cr_assert_stdout_eq_str(buffer, "");
}

Test(init_board, board_creation2, .init=redirect_all_std)
{
	game_board_t	*board = init_board(10, 5);
	char	*buffer =
		"*********************\n"
		"*         |         *\n"
		"*        |||        *\n"
		"*       |||||       *\n"
		"*      |||||||      *\n"
		"*     |||||||||     *\n"
		"*    |||||||||||    *\n"
		"*   |||||||||||||   *\n"
		"*  |||||||||||||||  *\n"
		"* ||||||||||||||||| *\n"
		"*|||||||||||||||||||*\n"
		"*********************\n\n";

	fflush(stdout);
	display_board(board);
	board = unset_board(board);
	cr_assert_stdout_eq_str(buffer, "");
}

Test(init_board, board_creation_error1, .init=redirect_all_std)
{
	game_board_t	*board = init_board(0, 1);
	char	*buffer = "Error: Wrong options, quitting...\n\n";

	fflush(stdout);
	fflush(stderr);
	board = NULL;
	(void)board;
	cr_assert_stderr_eq_str(buffer, "");
}

Test(init_board, board_creation_error2, .init=redirect_all_std)
{
	game_board_t	*board = init_board(1, 0);
	char	*buffer = "Error: Wrong options, quitting...\n\n";

	fflush(stdout);
	fflush(stderr);
	board = NULL;
	(void)board;
	cr_assert_stderr_eq_str(buffer, "");
}
