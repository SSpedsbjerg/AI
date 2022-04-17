#pragma once
#include <iostream>
#include <Occupier.h>
#include <tuple>

namespace TicTacToe {
	class Space {
	private:
		int x; int y;
		bool Occupied;
		TicTacToe::Occupier Occupier;

	public:
		Space(int posX, int posY) {
			x = posX; y = posY;
			Occupied = false;
		}

		bool getOccupation() {
			return Occupied;
		}

		TicTacToe::Occupier getOccupier() {
			if (Occupier == NULL) {
				return TicTacToe::Occupier(0);
			}
			else {
				return Occupier;
			}
		}

		void setOccupier(TicTacToe::Occupier oc) {
			this->Occupier = oc;
		}

		std::tuple<int, int> getPos() {
			return std::tuple<int, int>(x, y);
		}

	};
}