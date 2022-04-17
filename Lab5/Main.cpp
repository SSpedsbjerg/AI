#pragma once
#include <iostream>
#include "Player.h"
#include "AI.h"
#include "board.h"
#include "Occupier.h"

int main() {
	TicTacToe::Board board = TicTacToe::Board(3, 3, 3);
	TicTacToe::Player player = TicTacToe::Player(TicTacToe::Occupier::x, board);
	TicTacToe::AI ai = TicTacToe::AI(TicTacToe::Occupier::o, board);
	TicTacToe::Occupier starter = TicTacToe::Occupier::x;
	while (true) {
		std::cout << board.ToString() << std::endl;
		if (starter == player.getPlayerBrick()) {
			//player
			int x, y;
			std::cin >> x >> y;
			player.PlaceBrick(x, y);
			board = player.getBoard();
			//ai
			board = ai.MiniMax(board);
		}
	}
}