#include <ncursesw/curses.h>

#include "game.h"


void Game::draw() {
	Game::board_window();
	Game::brick_stats_window();
	Game::next_brick_window_func();
	Game::player_stats_window();
	Game::how_to_window();
}

void Game::board_window() {
	int color = 0;
	WINDOW * board = newwin(22,22,1,50);
	box(board, 0, 0);
	mvwprintw(board,0,8,"Tetris");
	// Rysownie siatki i klocka
	for(int row = 0; row < 20; row++) {
		for(int column = 0; column < 10; column++) {
			color = grid[row][column] + brick.grid[row + 4][column];
			wattron(board, COLOR_PAIR(color));
			// Rysowanie jako 2 znaki by klocki byly wizualnie wieksze
			mvwprintw(board, row + 1, column * 2 + 1, "  ");
			wattroff(board, COLOR_PAIR(color));
		}
	}
	wrefresh(board);
}

void Game::brick_stats_window() {
	int color = 0;
	
	// Gotowa siatka do statstyk klockow (zeby wyswietlaly sie na ekranie)
	int stats_bricks[20][7] {
		{0,0,0,0,0,0,0},
		{6,6,6,6,0,0,0},
		{0,0,0,0,0,0,0},
		{0,0,5,0,0,0,0},
		{0,5,5,5,0,0,0},
		{0,0,0,0,0,0,0},
		{0,1,1,0,0,0,0},
		{0,0,1,1,0,0,0},
		{0,0,0,0,0,0,0},
		{0,0,2,2,0,0,0},
		{0,2,2,0,0,0,0},
		{0,0,0,0,0,0,0},
		{0,3,3,0,0,0,0},
		{0,3,3,0,0,0,0},
		{0,0,0,0,0,0,0},
		{0,4,0,0,0,0,0},
		{0,4,4,4,0,0,0},
		{0,0,0,0,0,0,0},
		{0,0,0,7,0,0,0},
		{0,7,7,7,0,0,0},
	};
	
	WINDOW * brick_stats = newwin(22,16,1,34);
	box(brick_stats, 0, 0);
	mvwprintw(brick_stats, 0, 0, "Stats of Bricks");
	for(int row = 0; row < 20; row++) {
		for(int column = 0; column < 7 ; column++) {
			color = stats_bricks[row][column];
			wattron(brick_stats, COLOR_PAIR(color));
			mvwprintw(brick_stats, row + 1, column * 2 + 1, "  ");
			wattroff(brick_stats, COLOR_PAIR(color));
		}
	}
	
	// Wypisywanie statystyk klockow
	mvwprintw(brick_stats, 2,9," %d", brick_i);
	mvwprintw(brick_stats, 5,9," %d", brick_t);
	mvwprintw(brick_stats, 8,9," %d", brick_z);
	mvwprintw(brick_stats, 11,9," %d", brick_s);
	mvwprintw(brick_stats, 14,9," %d", brick_o);
	mvwprintw(brick_stats, 17,9," %d", brick_j);
	mvwprintw(brick_stats, 20,9," %d", brick_l);

	wrefresh(brick_stats);
}

void Game::next_brick_window_func() {
	int color = 0;
	WINDOW * next_brick_window = newwin(6,16,1,72);
	box(next_brick_window, 0, 0);
	mvwprintw(next_brick_window, 0, 3, "Next Brick");
	for(int row = 0; row < 4; row++) {
		for(int column = 0; column < 7; column++) {
			color = next_brick.grid[row][column + 1];
			wattron(next_brick_window, COLOR_PAIR(color));
			mvwprintw(next_brick_window, row + 1, column * 2 + 1, "  ");
			wattroff(next_brick_window, COLOR_PAIR(color));
		}
	}
	wrefresh(next_brick_window);
}

void Game::player_stats_window() {
	WINDOW * player_stats = newwin(8,16,7,72);
	box(player_stats, 0, 0);
	// Wypisywanie statystyk gracza
	mvwprintw(player_stats, 0, 2, "Player Stats");
	mvwprintw(player_stats, 1, 1, "Level: %d", level + 1);
	mvwprintw(player_stats, 2, 1, "Score: %d", score);
	mvwprintw(player_stats, 3, 1, "Lines: %d", completed_lines);
	wrefresh(player_stats);
}

void Game::how_to_window() {
	WINDOW * how_to = newwin(8,16,15,72);
	box(how_to, 0, 0);
	mvwprintw(how_to, 0, 2, "How to play");
	mvwprintw(how_to, 1, 1, "KEY_UP Rotate");
	mvwprintw(how_to, 2, 1, "KEY_DN Down");
	mvwprintw(how_to, 3, 1, "KEY_L  Left");
	mvwprintw(how_to, 4, 1, "KEY_R  Right");
	mvwprintw(how_to, 5, 1, "   P   Pause");
	mvwprintw(how_to, 6, 1, "   Q   Quit");
	wrefresh(how_to);
}


void Game::update() {
	// Sprawdzanie czy gra powinna sie zakonczyc 
	Game::end_game();
	
	bool collide =! brick.move_down();
	if(collide_with_bricks()) {
		brick.move_up();
		collide = true;
	}

	if(collide) {
		brick.spawn_brick();
		for(int row = 0; row < 20; row++) {
			for(int column = 0; column < 10; column++) {
				// Zapisywanie ustawionego klocka
				if(grid[row][column] == 0)
					grid[row][column] = brick.grid[row + 4][column];
			}
		}
		score_count();
		
		// Doliczanie klocka ktory zostal postawiony
		switch(brick.number) {
			case 0:
				brick_i ++;
				break;
			case 1:
				brick_t++;
				break;
			case 2:
				brick_z++;
				break;
			case 3:
				brick_s++;
				break;
			case 4:
				brick_o++;
				break;
			case 5:
				brick_l++;
				break;
			case 6:
				brick_j++;
				break;
		}
		
		brick = next_brick;
		next_brick = Brick();

	}
}

bool Game::collide_with_bricks() {
	brick.spawn_brick();
	for(int row = 0; row < 20; row++) {
		for(int column = 0; column < 10; column++) {
			// Sprawdzanie czy pola posiadaja inny numer niz 0 (kazdy inny oznacza klocek)
			if(grid[row][column] != 0 && brick.grid[row + 4][column] != 0)
				return true;
		}
	}
	return false;
}

void Game::score_count() {
	int row_cleared = 0;
	for(int row = 0; row < 20; row++) {
		if (is_row_completed(row)) {
			delete_row(row);
			row_cleared += 1;
		}
	}
	completed_lines += row_cleared;

	switch (row_cleared) {
		case 1:
			score += 40 * (level + 1);
			break;
		case 2:
			score += 100 * (level + 1);
			break;
		case 3:
			score += 300 * (level + 1);
			break;
		case 4:
			score += 1200 * (level + 1);
			break;
	};
	int count_lines = completed_lines - (5 * level);

	if (count_lines >= 5 && level < 9)
		level++;
}

bool Game::is_row_completed(int row) {
	for(int column = 0; column < 10; column++) {
		if(grid[row][column] == 0)
			return false;
	}
	return true;
}

void Game::delete_row(int n) {
	for(int row = n; row > 0; row--) {
		for(int column = 0; column < 10; column++) {
			// Nadpisywanie linii wyzej w celu "przesuniecia wszystykich klockow w dol"
			grid[row][column] = grid[row - 1][column];
		}
	}
	// Dodanie wyciętej linii do siatki
	for (int column = 0; column < 10; column++) {
		grid[0][column] = 0;
	}
}

void Game::pause_window() {
	WINDOW * pause = initscr();
	box(pause,0,0);
	mvwprintw(pause,13,58,"Pause");
	mvwprintw(pause,15,51,"Press p to continue");
	wrefresh(pause);
}

void Game::pause() {
	int input;
	Game::pause_window();
	while (true) {
		input = getch();
		if(input == 'p' | input == 'P') {
			clear();
			break;
		}
	}
}
void Game::end_game_window() {
	WINDOW * end_game = newwin(22,22,1,50);
	box(end_game, 0, 0);
	mvwprintw(end_game, 9, 7, "End Game");
	mvwprintw(end_game, 11, 3, "Press Q to quit");
	wrefresh(end_game);
}


void Game::end_game() {
	int input;
	// Sprawdzanie czy najwyzsza linia jest zajeta
	for(int column = 0; column < 10; column++) {
		if (grid[0][column] != 0) {
			Game::end_game_window();
			while(true) {
				input = getch();
				if(input == 'q' | input == 'Q') {
					playing = false;
					break;
				}
			}
		}
	}
}

void Game::moving(int key) {
	switch(key) {
		case KEY_DOWN:
			brick.move_down();
			if(collide_with_bricks())
				brick.move_up();
			break;
		case KEY_LEFT:
			brick.move_left();
			if(collide_with_bricks())
				brick.move_right();
			break;
		case KEY_RIGHT:
			brick.move_right();
			if(collide_with_bricks())
				brick.move_left();
			break;
		case KEY_UP:
			brick.rotation();
			if(collide_with_bricks())
				brick.undo_rotation();
			break;
		case 'p':
		case 'P':
			Game::pause();
			break;
		case 'q':
		case 'Q':
			// Przeywanie glownej petli w main
			playing= false;
			break;
	}
}