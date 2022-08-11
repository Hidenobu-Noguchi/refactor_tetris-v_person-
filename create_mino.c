#include "tetris.h"

extern const t_mino_shape	mino_set[MINO_TYPES];

t_mino	create_mino(void) {
	t_mino			new_mino;
	t_mino_shape	new_shape = mino_set[rand() % 7];

	new_mino.shape = new_shape;
	new_mino.pos.x = rand() % (COLUMN - (new_mino.shape.size + 1));
	new_mino.pos.y = 0;

	return (new_mino);
}

