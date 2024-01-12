#include <random>

#include "brick.h"
#include "bricks.h"

// Losowanie rodzaju klocka
Brick::Brick() {
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> type_gen(0,6);
	type = type_gen(gen);
	number = type;
	spawn_brick();

}

void Brick::spawn_brick() {
	for(int row = 0; row < 24; row++) {
		for(int column = 0; column < 10; column++) {
			// Rysowanie klocka
			if(row - y >= 0 && row - y < 4 && column - x >= 0 && column - x < 4)
				Brick::grid[row][column] = bricks[type][rotate][row - y][column - x];
			else
				Brick::grid[row][column] = 0;
		}
	}
}

bool Brick::is_brick_outside() {
	spawn_brick();
	int square = 0;
	for(int row = 0; row < 24; row++) {
		for(int column = 0; column < 10; column++) {
			// Sprawdzanie ile "kwadratow" (czesci skladowych klocka) znajduje sie na siatce
			if(grid[row][column] != 0)
				square += 1;
		}
	}
	if (square < 4) {
		return true;
	}
	return false;
}

void Brick::rotation() {
	rotate++;
	// Reset rotacji (sa dostepne tylko 4 dla kazdego klocka)
	if(rotate > 3)
		rotate = 0;
	if(is_brick_outside()) {
		undo_rotation();
	}
}

void Brick::undo_rotation() {
	rotate--;
	// Reset rotacji (sa dostepne tylko 4 dla kazdego klocka)
	if (rotate <= -1)
		rotate = 3;
}

bool Brick::move_down() {
	y++;
	if(is_brick_outside()) {
		y--;
		return false;
	}
	return true;
}

void Brick::move_left() {
	x--;
	if(is_brick_outside()) {
		x++;
	}
}

void Brick::move_right() {
	x++;
	if(is_brick_outside()) {
		x--;
	}
}

void Brick::move_up() {
	y--;
}