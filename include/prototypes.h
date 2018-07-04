/*
** EPITECH PROJECT, 2018
** prototypes.h
** File description:
** Header file for function prototypes
*/

#ifndef __MATCHSTICK_PROTO_H__
#define __MATCHSTICK_PROTO_H__

void	print_game_board(void);
void	print_updated_game_board(int line, int nb_matches);
void	display_board(char **board, int height, int width);
char	*select_line(char **game_board, int line);
void	remove_msticks_from_line(char *selected_line, int nb_matches);
void	read_player_move_and_print_updated_board_game(void);
int	check_max_matchsticks(char *selected_line);

#endif
