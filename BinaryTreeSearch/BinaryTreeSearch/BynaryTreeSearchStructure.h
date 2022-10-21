#pragma once
using namespace std;

struct node {
	int value;
	node* left;
	node* right;
	node(int _value) : value(_value), left(nullptr), right(nullptr) {}
};

class BynaryTreeSearch {
private:
	node* root = nullptr;
	node* min_elem_in_the_subtree(node*, node* descendant = nullptr);
public:
	void push(int, node* edge = nullptr);
	int search(int, node* edge = nullptr);
	int deleteNode(int, node* edge = nullptr, node* descendant = nullptr);
	int modifyTheValue(int, int);
	void clear(node* edge = nullptr);
	~BynaryTreeSearch();
};