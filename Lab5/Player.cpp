#pragma once
#include <iostream>
#include <Occupier.h>
#include <board.h>

namespace TicTacToe {
	class Player {
	private:
		TicTacToe::Occupier playerBrick;
		TicTacToe::Board board;
		static TicTacToe::Player* player;
	public:
		Player(TicTacToe::Occupier playerBrick, TicTacToe::Board board) {
			this->playerBrick = playerBrick;
			this->board = board;
		}

		TicTacToe::Occupier getPlayerBrick() {
			return playerBrick;
		}

		void setBoard(TicTacToe::Board board) {
			this->board = board;
		}

		TicTacToe::Board getBoard() {
			return board;
		}

		bool PlaceBrick(int x, int y) {
			return board.Place(playerBrick, x, y);
		}
	};
}

