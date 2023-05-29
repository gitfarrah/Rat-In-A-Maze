#pragma once
#include<iostream>
#include <vector>
using namespace std;

class StateSpaceTree
{
private:
	class Node {
	public:
		int data[2];
		vector<Node*> children;
		Node* parent;
		Node() {
		}
		Node(int x, int y) {
			data[0] = x;
			data[1] = y;
		}
	};

public:
	Node* root;
	Node* current_node;
	Node* xxx;
	StateSpaceTree();
	void insert(int x, int y);
	void movetoparent();
	void display(Node* temp_root);
	void display_tree(Node* node);
	char direction(Node* parent, Node* child);
};