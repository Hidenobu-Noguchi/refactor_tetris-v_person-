#include "tetris.h"

extern int				get_score;
extern struct timeval	starting_time;
extern t_mino			current_mino;
extern int				is_running;

void	initialize_game() {
	t_mino	new_mino = create_mino();
   
    initscr();
	gettimeofday(&starting_time, NULL);
	timeout(1);
	srand((unsigned int)starting_time.tv_usec);

	get_score = 0;
	current_mino = new_mino;

	if(!check_mino_position(current_mino))
		is_running = FALSE;
	print_table();
}
