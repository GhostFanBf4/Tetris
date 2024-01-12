#include <ncursesw/curses.h>

#include "game.h"

void ncurses_prep() {
	initscr();
	// Przypisywanie podstawowych kolorow ncurses
	start_color();
	for(int color = 1; color < 8; color++)
		init_pair(color, 0, color);
	keypad(stdscr, TRUE);
	noecho();
	curs_set(0);

	// timeout dla getch (spadanie klockow)
	timeout(60);
}


int main() {
	int input = 0;
	Game game;
	ncurses_prep();

	// Glowna petla
	while(game.playing) {
		// Pod pętla glowna odpowiada za przesowanie klockow po siatce (oraz nadawanie "predkosci")
		for(int speed = 0; speed < 10 - game.level; speed++) {
			game.draw();
			input = getch();
			game.moving(input);
		}
		game.update();
	}
	endwin();
}