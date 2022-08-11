#ifndef TETRIS_H
# define TETRIS_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <ncurses.h>

#define ROW 20
#define COLUMN 15
#define	MINO_TYPES 7
#define	SQUARE_SIZE 4
#define TRUE 1
#define FALSE 0

typedef unsigned char	t_mino_array[SQUARE_SIZE][SQUARE_SIZE];

typedef struct s_mino_shape	t_mino_shape;
typedef struct s_position	t_position;
typedef struct s_mino		t_mino;

struct s_mino_shape {
	t_mino_array	array;
	int				size;
};

struct s_position {
	int	x;
	int	y;
};

struct s_mino {
	t_mino_shape	shape;
	t_position		pos;
};

void	initialize_game();
void	finish_game();
t_mino	create_mino(void);
int 	check_mino_position(t_mino mino);
void	print_table();

#endif
