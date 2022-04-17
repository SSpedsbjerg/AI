#include <iostream>
#include <vector>
#include <board.h>
#include "Node.h"

namespace TicTacToe {
	class Node {
	private:
		TicTacToe::Board board;
		Node* parent;
		std::vector<Node*> children;
		TicTacToe::Occupier currentTurn;
		int layer;
		int outCome; //1 if x wins, -1 if o wins, 0 if draw
	public:
		Node::Node() {

		}

		Node::Node(TicTacToe::Board board) {
			this->board = board;
			layer = 0;
		}

		Node::Node(TicTacToe::Board board, Node* parent) {
			this->board = board;
			this->parent = parent;
			addChild(this);
			this->layer = parent->getLayer() + 1;
		}

		TicTacToe::Board Node::getBoard() {
			return board;
		}

		//returns 1 if x won, -1 if x lost, and 0 if draw
		int Node::getOutcome() {
			return board.checkIfWon();
		}

		void Node::addChild(Node* child) {
			children.push_back(child);
		}

		bool Node::hasChildren() {
			if (children.size() == 0) {
				return false;
			}
			else {
				return true;
			}
		}

		Node* Node::getChild(int i) {
			return children[i];
		}

		int Node::getChildrenSize() {
			return children.size();
		}
		int Node::getLayer() {
			return layer;
		}
	};
}