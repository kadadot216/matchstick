#ifndef __MATCHSTICK_ENUMS_H__
#define __MATCHSTICK_ENUMS_H__

enum	board_status_e {
	EMPTY,
	SET,
	FINISHED,
	ERROR
};

enum	prompt_error_e {
	LINE_MATCHES_OOB = 0,
	INVALID_PROMPT = 1,
	ZERO_MATCHES = 2,
	NOT_ENGH_MATCHES = 3,
	PROMPT_OK = 42
};

enum	game_status_e {
	RUNNING,
	PLAYER_WON,
	AI_WON
};

enum	turn_type_e {
	PLAYER,
	AI
};

#endif
