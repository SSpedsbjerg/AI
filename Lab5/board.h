#pragma once
#include <Occupier.h>
#include <string>

namespace TicTacToe {
	class Board {
	public:
		Board();

		Board(int rowNeeded);

		Board(int sizeX, int sizeY);

		Board(int sizeX, int sizeY, int rowNeeded);

		//returns 1 if won, 0 if draw, -1 if lost
		int checkIfWon();

		int getSizeX();

		int getSizeY();

		int rowLength();

		bool isFull();

		std::string ToString();

		bool Place(TicTacToe::Occupier oc, int x, int y);
	};
}
