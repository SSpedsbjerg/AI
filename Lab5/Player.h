#pragma once
#include <Occupier.h>
#include <Player.cpp>
#include <board.h>

namespace TicTacToe {
	class Player {
	public:

		Player(TicTacToe::Occupier oc, TicTacToe::Board board);

		TicTacToe::Occupier getPlayerBrick();

		void setBoard(TicTacToe::Board board);

		TicTacToe::Board getBoard();

		bool PlaceBrick(int x, int y);
	};

}