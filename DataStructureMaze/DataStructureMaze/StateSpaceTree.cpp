#include "StateSpaceTree.h"
#include<string>
StateSpaceTree::StateSpaceTree()
{
	root = new Node(0, 0);
	current_node = root;
}

void StateSpaceTree::insert(int x, int y)
{
	if (!(x == 0 && y == 0))
	{
		Node* newNode = new Node(x, y);
		newNode->parent = current_node;
		current_node->children.push_back(newNode);
		current_node = newNode;
	}
}

void StateSpaceTree::movetoparent()
{
	current_node = current_node->parent;
}

void StateSpaceTree::display(Node* temp_root)
{


	for (int i = 0; i < temp_root->children.size(); i++)
	{

		display(temp_root->children[i]);
		cout << "(" << temp_root->data[0] << "," << temp_root->data[1] << ") ";
	}
	cout << endl;
}
char StateSpaceTree::direction(Node* parent, Node* child) {
	if (child->data[0] - parent->data[0] > 0) {
		return 'R';
	}
	else if (child->data[0] - parent->data[0] < 0) {
		return 'L';
	}
	else if (child->data[1] - parent->data[1] > 0) {
		return 'D';
	}
	else if (child->data[1] - parent->data[1] < 0) {
		return 'U';
	}
}

void StateSpaceTree::display_tree(Node* node) {

	string str = to_string(node->data[0]) + "|" + to_string(node->data[1]) + " -> ";
	for (int i = 0; i < node->children.size(); i++) {
		str = str + direction(node, node->children[i]) + ", ";
	}
	str += ".";
	cout << endl;
	cout << str;
	for (int i = 0; i < node->children.size(); i++) {
		display_tree(node->children[i]);
	}
}
