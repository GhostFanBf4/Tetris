#ifndef BRICK_H
#define BRICK_H

class Brick {
	public:
		Brick();
		// Glowne rysowanie klocka na siatce
		void spawn_brick();
		// Rotacja klockow
		void rotation();
		void undo_rotation();
		// Poruszanie sie klockami
		bool move_down();
		void move_left();
		void move_right();
		void move_up();
		// Prawdziwa siatka po ktorej "ruszaja" sie klocki
		int grid[24][10] = {};
		// Numer rodzaju klocka
		int number = 0;

	private:
		// Sprawdzanie czy klocek wychodzi poza okno
		bool is_brick_outside();
		// Wymiary klocków
		int x = 3;
		int y = 1;

		int type = 0;
		int rotate = 0;
};

#endif