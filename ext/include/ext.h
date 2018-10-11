#ifndef __GAME_H__
#define __GAME_H__

#include "types.h"

typedef void	(*ai_strat_t)(p_choice_t *, game_board_t *);

int	random_iv(int min, int max);
game_status_t	ext_play_game(game_board_t *board, int diff_choice);
game_status_t	check_for_win_condition(game_board_t *board, turn_type_t tt);
game_status_t	play_turn(game_board_t *board, turn_type_t type);
game_status_t	get_input_choice(p_choice_t *c, game_board_t *b);
void	airand_get_input_choice(p_choice_t *c, game_board_t *b);
void	ext_print_help_msg(char *pname);
void	ext_print_seldiff(int ai_lvl);
void	invalid_diff_info(void);
int	parse_difficulty(char *arg);
int	my_strcmp(char const *s1, char const *s2);
int	my_str_isalpha(char const *str);
char	*my_strlowcase(char *str);
char	*my_strdup(char const *src);


#endif /* __GAME_H__ */
