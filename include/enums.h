#ifndef __MATCHSTICK_ENUMS_H__
#define __MATCHSTICK_ENUMS_H__

enum	board_status_e {
	EMPTY,
	SET,
	FINISHED,
	ERROR
};

enum	game_status_e {
	RUNNING,
	PLAYER_WON,
	AI_WON,
	EOF_QUIT,
	ABORT = 0
};

enum	turn_type_e {
	PLAYER,
	AI
};

#endif
