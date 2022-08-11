tetris: tetris.c
	gcc tetris.c -lncurses -o tetris

sample: sample.c initialize_game.c finish_game.c create_mino.c check_mino_position.c print_table.c
	gcc -I./ sample.c initialize_game.c finish_game.c create_mino.c check_mino_position.c print_table.c -lncurses -o tetris
