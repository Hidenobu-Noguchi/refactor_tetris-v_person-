#include "tetris.h"

char			game_field[ROW][COLUMN] = {0};
int				get_score = 0;
char			is_running = TRUE;
suseconds_t		interval = 400000;
int				up_speed = 1000;
struct timeval	starting_time;
struct timeval 	present_time;
t_mino			current_mino;

const t_mino_shape	mino_set[MINO_TYPES] = {
	{
		.array = {
			{0, 1, 1, 0},
			{1, 1, 0, 0},
			{0, 0, 0, 0},
			{0, 0, 0, 0},
		},
		.size = 3,
	},
	{
		.array = {
			{1, 1, 0, 0},
			{0, 1, 1, 0},
			{0, 0, 0, 0},
			{0, 0, 0, 0},
		},
		.size = 3,
	},
	{
		.array = {
			{0, 1, 0, 0},
			{1, 1, 1, 0},
			{0, 0, 0, 0},
			{0, 0, 0, 0},
		},
		.size = 3,
	},
	{
		.array = {
			{0, 0, 1, 0},
			{1, 1, 1, 0},
			{0, 0, 0, 0},
			{0, 0, 0, 0},
		},
		.size = 3,
	},
	{
		.array = {
			{1, 0, 0, 0},
			{1, 1, 1, 0},
			{0, 0, 0, 0},
			{0, 0, 0, 0},
		},
		.size = 3,
	},
	{
		.array = {
			{1, 1, 0, 0},
			{1, 1, 0, 0},
			{0, 0, 0, 0},
			{0, 0, 0, 0},
		},
		.size = 2,
	},
	{
		.array = {
			{0, 0, 0, 0},
			{1, 1, 1, 1},
			{0, 0, 0, 0},
			{0, 0, 0, 0},
		},
		.size = 4,
	},
};

void	rotate_mino(t_mino *mino) {
	t_mino_shape	before_shape = mino->shape;
	int 			width = mino->shape.size;
	int				k;

	for(int i = 0; i < width; i++){
		for(int j = 0, k = width - 1; j < width; j++, k--){
				mino->shape.array[i][j] = before_shape.array[k][i];
		}
	}
}

// void	execute_command(void)
void	execute_command(int c)
{
	t_mino	new_mino;
	t_mino	temp_mino = current_mino;

	switch(c){
		case 's':
			temp_mino.pos.y++;
			if(check_mino_position(temp_mino))
				current_mino.pos.y++;
			else {
				for(int i = 0; i < current_mino.shape.size ;i++) {
					for(int j = 0; j < current_mino.shape.size ; j++) {
						if(current_mino.shape.array[i][j])
							game_field[current_mino.pos.y + i][current_mino.pos.x + j] = current_mino.shape.array[i][j];
						}
					}
					int sum, count = 0;
					for(int n = 0; n < ROW; n++) {
						sum = 0;
						for(int m = 0; m < COLUMN; m++) {
							sum += game_field[n][m];
						}
						if(sum == COLUMN) {
							count++;
							int k;
							for(k = n; k >= 1; k--)
								for(int l = 0; l < COLUMN; l++)
									game_field[k][l] = game_field[k - 1][l];
							for(int l = 0; l < COLUMN ; l++)
								game_field[k][l] = 0;
							interval -= up_speed;
							up_speed--;
						}
					}
					get_score += 100 * count;
					new_mino = create_mino();
					new_mino.pos.x = rand() % (COLUMN - new_mino.shape.size + 1);
					new_mino.pos.y = 0;
					current_mino = new_mino;
					if(!check_mino_position(current_mino))
						is_running = FALSE;
			}
			break;

		case 'd':
			temp_mino.pos.x++;
			if(check_mino_position(temp_mino))
				current_mino.pos.x++;
			break;

		case 'a':
			temp_mino.pos.x--;
			if(check_mino_position(temp_mino))
				current_mino.pos.x--;
			break;

		case 'w':
			rotate_mino(&temp_mino);
			if(check_mino_position(temp_mino))
				rotate_mino(&current_mino);
			break;
	}
	print_table();
}

int is_time_to_update() {
	suseconds_t	present_tm = (present_time.tv_sec * 1000000) + present_time.tv_usec;
	suseconds_t	start_tm = (starting_time.tv_sec * 1000000) + starting_time.tv_usec;

	return (present_tm - start_tm) > interval;
	// return ((suseconds_t)((present_time.tv_sec * 1000000) + present_time.tv_usec) - (suseconds_t)((starting_time.tv_sec * 1000000) + starting_time.tv_usec)) > interval;
}

void	running_game()
{
	int		c;

	while(is_running) {
		if ((c = getch()) != ERR)
			execute_command(c);
		gettimeofday(&present_time, NULL);
		if (is_time_to_update())
		{
			execute_command('s');
			gettimeofday(&starting_time, NULL);
		}
	}
}

int main() {
	initialize_game();
	running_game();
	finish_game();

    return 0;
}
