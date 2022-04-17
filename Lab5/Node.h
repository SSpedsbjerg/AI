#pragma once
#include <iostream>
#include <vector>
#include <board.h>
#include <Player.h>

namespace TicTacToe {
	class Node {
	public:
		Node();

		Node::Node(TicTacToe::Board board);

		Node(TicTacToe::Board board, Node* parent);

		TicTacToe::Board getBoard();

		void addChild(Node* child);

		bool hasChildren();

		Node* getChild(int i);

		int getChildrenSize();

		int getLayer();
	};
}