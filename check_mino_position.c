#include "tetris.h"

extern char	game_field[ROW][COLUMN];

int check_mino_position(t_mino mino) {
	for(int i = 0; i < mino.shape.size; i++) {
		for(int j = 0; j < mino.shape.size; j++) {
			int	x = mino.pos.x + j;
			int	y = mino.pos.y + i;

			if (y < 0 || ROW <= y || x < 0 || COLUMN <= x) {
				if (mino.shape.array[i][j])
					return FALSE;
			}
			else if (game_field[y][x] && mino.shape.array[i][j])
				return FALSE;
		}
	}
	return TRUE;
}
