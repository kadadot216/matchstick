##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile for my_runner
##

CC		=	gcc -W -Wall -Wextra
DBCC		=	gcc -g
RM		=	rm -f

#	Library settings
LIB_DIR		=	lib
LIB_NAMEDIR	=	my
LIB_PATH	=	$(LIB_DIR)/$(LIB_NAMEDIR)

LIB_HDPATH	=	$(LIB_PATH)/include

LIB_HDSRC	=	my.h			\
			gnl_simplified.h

LIB_HDS		=	$(addprefix $(LIB_HDPATH)/, $(LIB_HDSRC))

LIB_SRCS	=	my_putchar_fd.c		\
			my_putcharx_fd.c	\
			my_putstr_fd.c		\
			my_put_nbr_fd.c		\
			my_getnbr.c		\
			my_strtablen.c		\
			my_str_isnum.c		\
			my_strlen.c		\
			my_memset.c		\
			gnl_simplified.c

LIB_SRC		=	$(addprefix $(LIB_PATH)/, $(LIB_SRCS))
LIB_OBJ		=	$(LIB_SRC:.c=.o)
LIB_NAME	=	lib$(LIB_NAMEDIR).a

#	Program settings
HDPATH		=	./include
CFLAGS		+=	-I$(HDPATH)
NAME		=	matchstick
LDFLAGS		=	-L./lib
LIBFLAG		=	-lmy
SRC		=	src/board/build.c		\
			src/board/build_map.c		\
			src/board/build_sticks.c	\
			src/board/destroy.c		\
			src/board/update.c		\
			src/helpers/ms_free_strtab.c	\
			src/helpers/ms_free_uinttab.c	\
			src/helpers/ms_uinttabcpy.c	\
			src/display/display_board.c	\
			src/display/game_messages.c	\
			src/game/game_loop.c		\
			src/game/user_prompt.c		\
			src/game/checking.c		\
			src/game/print_err_functs.c	\
			src/game/value_checks.c		\
			src/ai/strategy.c		\
			src/parsing.c
			
MAIN		=	src/main.c

OBJ		=	$(SRC:.c=.o)
OBJ		+=	$(MAIN:.c=.o)

#	Tests settings
TEST_NAME	=	unit_tests
TEST_SRC	=	tests/redirect_all_std.c	\
			tests/board_creation.c		\
			tests/player_move.c
TEST_FLAGS	=	--coverage -lcriterion

GDB_MAIN	=	$(MAIN)
GDB_NAME	=	gdb.out
BONUS_MAIN	=	bonus/main.c
BONUS_SRC	=	bonus/ai_random.c		\
			bonus/bonus_game_loop.c		\
			bonus/random_iv.c		\
			bonus/select_difficulty.c
BONUS_INCLUDE	=	-I./bonus/include


.PHONY: tclean gclean fclean lclean lfclean $(NAME)

all:	$(NAME)

#	Library rules
lib:	libh liba

libh:
	@mkdir -p $(LIB_DIR)/$(HDPATH)
	cp $(LIB_HDS) $(HDPATH)

liba:	$(LIB_OBJ)
	ar rc $(LIB_DIR)/$(LIB_NAME) $^

libclean:
	$(RM) $(LIB_OBJ)

libfclean: libclean
	rm -rf $(LIB_DIR)/$(HDPATH)
	$(RM) $(LIB_DIR)/$(LIB_NAME)

re: libfclean lib

#	Program rules
$(NAME): lib
	$(CC) $(CFLAGS) $(LDFLAGS) -o $(NAME) $(MAIN) $(SRC) $(LIBFLAG)
re: clean cclean $(NAME)

clean:
	$(RM) $(OBJ)

cclean:	clean
	$(RM) $(HDTGR)
	$(RM) $(LIBTGR)
	$(RM) $(NAME)

#	Tests rules
gdb:	gclean lib
	$(DBCC) $(CFLAGS) $(LDFLAGS) -o $(GDB_NAME) $(GDB_MAIN) $(SRC)	\
		$(LIB_SRC) $(LDLIBS) $(LIBFLAG)

gclean:
	$(RM) $(GDB_NAME)

tests_run:
	$(CC) $(CFLAGS) -I./tests/include -o $(TEST_NAME) $(TEST_SRC) $(SRC) \
		$(LIB_SRC) $(TEST_FLAGS)
	./$(TEST_NAME)

tclean:
	$(RM) *.gc*
	$(RM) *vg*
	$(RM) $(TEST_NAME)

bonus: lib
	$(CC) $(CFLAGS) $(BONUS_INCLUDE) $(LDFLAGS) -o $(NAME) $(BONUS_MAIN) \
		$(SRC) $(BONUS_SRC) $(LIBFLAG)

bclean: cclean libfclean
	$(RM) ./bonus/*.o

fclean: tclean gclean cclean libfclean
