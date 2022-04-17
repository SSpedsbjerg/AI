#pragma once
#include <Player.cpp>
#include <vector>
#include <iostream>
#include <tuple>
#include <Lab5/Node.h>

namespace TicTacToe {
	class AI {
	public:
		AI(TicTacToe::Occupier playerBrick, TicTacToe::Board board);

		TicTacToe::Board RandomMove(TicTacToe::Board board);

		TicTacToe::Board MiniMax(TicTacToe::Board board);
	};
}