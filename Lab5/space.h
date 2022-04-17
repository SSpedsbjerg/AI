#pragma once
#include <Occupier.h>


namespace TicTacToe {
	class Space {
	private:
		int x; int y;
		bool Occupied;
		TicTacToe::Occupier Occupier;

	public:
		Space(int posX, int posY);

		bool getOccupation();

		TicTacToe::Occupier getOccupier();

		void setOccupier(TicTacToe::Occupier oc);

		std::tuple<int, int> getPos();
	};
}