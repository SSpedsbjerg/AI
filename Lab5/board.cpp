#pragma once
#include <iostream>
#include <space.h>
#include <vector>
#include <tuple>
#include <algorithm>
#include "board.h"

namespace TicTacToe {
	class Board {
	private:
		int x;
		int y;
		int neededRowForWinning = 3;
		std::vector<TicTacToe::Space> board;
		bool compare(TicTacToe::Space space0, TicTacToe::Space space1) {
			if (std::get<0>(space0.getPos()) > std::get<0>(space1.getPos())) {
				return true;
			}
			else if (std::get<0>(space0.getPos()) < std::get<0>(space1.getPos())) {
				return false;
			}
			else {
				if (std::get<1>(space0.getPos()) > std::get<1>(space1.getPos())) {
					return true;
				}
				else {
					return false;
				}
			}
		}

		void createBoard() {
			for (int i = 0; i < x; i++) {
				for (int j = 0; j < y; j++) {
					board.push_back(TicTacToe::Space(i, j));
				}
			}
			std::sort(board.begin(), board.end(), compare);
		}

	public:
		Board::Board() {
			this->x = 3; this->y = 3;
			createBoard();
		}

		Board::Board(int rowNeeded) {
			this->x = 3; this->y = 3; this->neededRowForWinning = rowNeeded;
			createBoard();
		}

		Board::Board(int sizeX, int sizeY) {
			this->x = sizeX; this->y = sizeY;
			createBoard();
		}

		Board::Board(int sizeX, int sizeY, int rowNeeded) {
			this->x = sizeX; this->y = sizeY; this->neededRowForWinning = rowNeeded;
			createBoard();
		}

		//returns 1 if X won, 0 if draw, -1 if X lost
		int Board::checkIfWon() {
			using namespace TicTacToe;
			std::vector<Space> values;
			
			for (int i = 0; i < x; i++) {
				for (int j = 0; j < y; i++) {
					values.insert(values.begin(), getSpace(i, j));
					//if values are larger than max, just pop the last one and continue
					if (values.size() > neededRowForWinning) {
						values.pop_back();
					}
					//check all of the values if they are the same
					if (values.size() == neededRowForWinning) {
						Occupier oc = values[0].getOccupier();

						for (int k = 0; k < neededRowForWinning; ++k) {

							if (values[k - 1].getOccupier() == oc) {

								if (k == neededRowForWinning) {

									if (oc == Occupier::x) {
										return 1;
									}
									else {
										return -1;
									}
								}
							}
							else {
								break;
							}
						}
					}
				}
			}
			return 0;
		}

		TicTacToe::Space Board::getSpace(int x, int y) {
			for (int i = 0; i < board.size(); i++) {
				if (std::get<0>(board[i].getPos()) == x && std::get<1>(board[i].getPos()) == y) {
					return board[i];
				}
			}
		}

		int Board::getSizeX() {
			return this->x;
		}

		int Board::getSizeY() {
			return this->y;
		}

		int Board::rowLength() {
			return neededRowForWinning;
		}

		bool Board::isFull() {
			for (int i = 0; i < board.size(); i++) {
				if (board[i].getOccupation() == false) {
					return false;
				}
			}
			return true;
		}

		std::string Board::ToString() {
			using namespace std;
			string returnString;
			for (int i = 0; i < this->x; i++) {
				for (int j = 0; j < this->y; j++) {
					if (board[j].getOccupier() == TicTacToe::Occupier::x) {
						returnString += string("X");
					}
					else if (board[j].getOccupier() == TicTacToe::Occupier::o) {
						returnString += string("O");
					}
					else {
						returnString += string("Z");
					}
				}
				returnString += string("\n");
			}
			
		}

		bool Board::Place(TicTacToe::Occupier oc, int x, int y) {
			for (int i = 0; i < board.size(); i++) {
				if (std::get<0>(board[i].getPos()) == x && std::get<1>(board[i].getPos()) == y) {
					if (!board[i].getOccupation()) {
						board[i].setOccupier(oc);						
						checkIfWon();
						return true;
					}
					else {
						return false;
					}
				}
			}
			return false;
		}


	};
}
