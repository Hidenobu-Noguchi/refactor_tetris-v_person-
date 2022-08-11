#include "tetris.h"

extern char		game_field[ROW][COLUMN];
extern int		get_score;
extern t_mino	current_mino;

static void	add_if_exist_mino(char (*mino_pos)[15], int row, int col)
{
	if(current_mino.shape.array[row][col])
		mino_pos[current_mino.pos.y + row][current_mino.pos.x + col] = current_mino.shape.array[row][col];
}

static void	add_current_mino_pos(char (*mino_pos)[15])
{
	for(int row = 0; row < current_mino.shape.size ;row++) {
		for(int col = 0; col < current_mino.shape.size ; col++) {
			add_if_exist_mino(mino_pos, row, col);
		}
	}
}

static void	print_title() {
	for(int i = 0; i < COLUMN - 9; i++)
		printw(" ");
	printw("42 Tetris\n");
}

static void	print_game_table(char (*mino_pos)[15]) {
	for(int i = 0; i < ROW ; i++) {
		for(int j = 0; j < COLUMN ; j++) {
			printw("%c ", (game_field[i][j] + mino_pos[i][j]) ? '#' : '.');
		}
		printw("\n");
	}
}

static void	print_score() {
	printw("\nScore: %d\n", get_score);
}

void	print_table() {

	char current_mino_pos[ROW][COLUMN] = {0};

	add_current_mino_pos(current_mino_pos);
	clear();
	print_title();
	print_game_table(current_mino_pos);
	print_score();
}
