#pragma once
#include <Player.cpp>
#include <vector>
#include <iostream>
#include <tuple>
#include <Lab5/Node.h>

namespace TicTacToe {
	class AI {
	private:
		TicTacToe::Occupier playerBrick;
		std::vector<TicTacToe::Board> outcomes;
		TicTacToe::Board board;
		TicTacToe::Node startNode;
		std::vector<Node> nodes;

		bool boardsFree() {
			for (int i = 0; i < nodes.size(); i++) {
				if (nodes[i].hasChildren() == false) {
					if (nodes[i].getBoard().isFull() == false) return false;
				}
			}
			return true;
		}

		//goes through all nodes until it finds the end, then it goes up the chain again and looking at who turn it was and deciding from there which is best
		int getLikelyOutcome(Node* node) {
			//node.getLayer() % 2 == 0 #x's turn
			//node.getLayer() % 2 == 1 #o's turn
			Node* currentNode;
			std::vector<std::tuple<int, Node*>> outComes;
			if (node->hasChildren()) {
				int i = 0;
				while (node->hasChildren()) {
					int outCome = getLikelyOutcome(node->getChild(i));
					outComes.push_back(std::tuple<int, Node*>{outCome, node});
					i++;
				}
				//X turn
				if (node->getLayer() % 2 == 0) {
					int hightValueNode = std::get<0>(outComes[0]);
					
					for (int i = 0; i < outComes.size(); i++) {
						if (hightValueNode == 1) {
							return 1;
						}
						if (std::get<0>(outComes[i]) > hightValueNode) {
							hightValueNode = std::get<0>(outComes[i]);
						}
					}
					return hightValueNode;
				}
				//O turn
				else if (node->getLayer() % 2 == 1) {
					int lowestValueNode = std::get<0>(outComes[0]);

					for (int i = 0; i < outComes.size(); i++) {
						if (lowestValueNode == -1) {
							return -1;
						}
						if (std::get<0>(outComes[i]) < lowestValueNode) {
							lowestValueNode = std::get<0>(outComes[i]);
						}
					}
					return lowestValueNode;
				}
			}
			else {
				return node->getBoard().checkIfWon();
			}
		}

		void createPossibleOutComes() {
			TicTacToe::Node startNode = TicTacToe::Node(TicTacToe::Board(board.getSizeX(), board.getSizeY(), board.rowLength()));

			TicTacToe::Occupier turn;

			Node currentNode = startNode;
			do {
				TicTacToe::Board newBoard = Board(board.getSizeX(), board.getSizeY(), board.rowLength());
				for (int i = 0; i < board.getSizeX(); i++) {
					for (int j = 0; j < board.getSizeY(); j++) {
						bool success = newBoard.Place(turn, i, j);
						if (!success) std::cout << "Space was occupied" << std::endl;
						else {
							nodes.push_back(TicTacToe::Node(newBoard));
							currentNode.addChild(&nodes.back());
							std::cout << "fond space" << std::endl;
						}
					}
				}
				//switch turn
				if (turn == TicTacToe::Occupier::x) {
					turn = TicTacToe::Occupier::o;
				}
				else {
					turn = TicTacToe::Occupier::x;
				}
			}
			while (!boardsFree());
		}

		void createPossibleOutComes(TicTacToe::Board board) {
			TicTacToe::Node startNode = TicTacToe::Node(board);

			TicTacToe::Occupier turn;

			Node currentNode = startNode;
			do {
				TicTacToe::Board newBoard = Board(board.getSizeX(), board.getSizeY(), board.rowLength());
				for (int i = 0; i < board.getSizeX(); i++) {
					for (int j = 0; j < board.getSizeY(); j++) {
						bool success = newBoard.Place(turn, i, j);
						if (!success) std::cout << "Space was occupied" << std::endl;
						else {
							nodes.push_back(TicTacToe::Node(newBoard));
							currentNode.addChild(&nodes.back());
							std::cout << "fond space" << std::endl;
						}
					}
				}
				//switch turn
				if (turn == TicTacToe::Occupier::x) {
					turn = TicTacToe::Occupier::o;
				}
				else {
					turn = TicTacToe::Occupier::x;
				}
			} 			
			while (!boardsFree());
		}

	public:
		AI(TicTacToe::Occupier playerBrick, TicTacToe::Board board) {
			this->playerBrick = playerBrick;
			this->board = board;
		}

		TicTacToe::Board RandomMove(TicTacToe::Board board) {
			this->board = board;
			createPossibleOutComes(board);
			srand(time(NULL));
			return outcomes[rand() % outcomes.size() + 1];
		}

		TicTacToe::Board MiniMax(TicTacToe::Board board) {
			this->board = board;
			createPossibleOutComes(board);
			//if AI is X
			if (playerBrick == TicTacToe::Occupier::x) {
				//find one where it will win
				for (int i = 0; i < outcomes.size(); i++) {
					if (getLikelyOutcome(&TicTacToe::Node(outcomes[i])) == 1) {
						return outcomes[i];
					}
				}
				//find one where it will draw
				for (int i = 0; i < outcomes.size(); i++) {
					if (getLikelyOutcome(&TicTacToe::Node(outcomes[i])) == 1) {
						return outcomes[i];
					}
				}
				//I'm to lazy to make it look for best possible in case all hope is lost, so its just going to pick random and hope furture will be better
				srand(time(NULL));
				return outcomes[rand() % outcomes.size() + 1];
			}
		}
	};
}