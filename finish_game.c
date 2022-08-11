#include "tetris.h"

extern char	game_field[ROW][COLUMN];
extern int	get_score;

static void	print_last_table() {
	for(int i = 0; i < ROW ;i++) {
		for(int j = 0; j < COLUMN ; j++) {
			printf("%c ", game_field[i][j] ? '#': '.');
		}
		printf("\n");
	}
}

static void	print_game_over() {
	printf("\nGame over!\n");
}

static void	print_last_score() {
	printf("\nScore: %d\n", get_score);
}

void	finish_game() {
	endwin();
	print_last_table();
	print_game_over();
	print_last_score();
}
