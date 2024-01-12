#ifndef GAME_H
#define GAME_H

#include "brick.h"


class Game {
	public:
		Game():brick() {};
		// Glowna funkcja przywolujaca
		void draw();
		// Funkcja aktualizaujaca w momencie kiedy klocek nie moze ruszyc sie nizej
		void update();
		// Glowna funkcja przywolujaca funkcje rychu
		void moving(int);
		// Zmienna dzieki ktorej dziala glowna petla
		bool playing = true;
		int level = 0;

	private:
		Brick brick;
		Brick next_brick;

		bool collide_with_bricks();
		bool is_row_completed(int);
		void delete_row(int);
		void score_count();

		// Okienka
			// Glowne okno gry
		void board_window();
			// Ilosc pojawionych sie klockow w ciagu gry
		void brick_stats_window();
		void player_stats_window();
			// Okno z nastepnym klockiem jaki sie pojawi
		void next_brick_window_func();
			// Okno z instrukcjami jak grac
		void how_to_window();
		void end_game_window();
		void pause_window();

		void pause();
		void end_game();
		int score = 0;
		int completed_lines = 0;
		// Siatka "widoczna dla uzytkownika"
		int grid[20][10] = {};
		// Zmienne przechowujace ilosc wystapien przypisanych klockow
		int brick_i = 0;
		int brick_z = 0;
		int brick_j = 0;
		int brick_l = 0;
		int brick_o = 0;
		int brick_s = 0;
		int brick_t = 0;
};

#endif