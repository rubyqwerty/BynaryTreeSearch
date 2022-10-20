#include"BynaryTreeSearchStructure.h"

void BynaryTreeSearch::push(int value, node* edge)
{
	if (!root)	root = new node(value);
	else
	{
		if (!edge) edge = root;
		if (value < edge->value)
			if (!edge->left)
				edge->left = new node(value);
			else
				push(value, edge->left);
		else
			if (!edge->right)
				edge->right = new node(value);
			else
				push(value, edge->right);
	}
}

int BynaryTreeSearch::search(int key, node* edge)
{
	if (!root)	return 0;
	if (!edge) edge = root;
	if (key == edge->value) return 1;
	if (key < edge->value)
		if (!edge->left)
			return 0;
		else
			search(key, edge->left);
	else
		if (!edge->right)
			return 0;
		else
			search(key, edge->right);
}

node* BynaryTreeSearch::min_elem_in_the_subtree(node* edge)
{
	if (!edge->left && !edge->right)
	{
		return new node(edge->value);
		delete edge;
	}
	if (!edge->left)
	{
		return edge;
	}
	min_elem_in_the_subtree(edge->left);
}

int BynaryTreeSearch::deleteNode(int key, node* edge, node* descendant)
{
	if (!root)	return -1; //нелзья удалить корень дерева
	if (!edge) edge = root;
	if (key == edge->value)
	{
		if (!edge->left && !edge->right)
		{
			if (descendant->value > edge->value) descendant->left = nullptr;
			else  descendant->right = nullptr;
			delete edge;
		}
		else if (edge->left && edge->right)
		{
			//
		}
		else if (edge->left)
		{
			if (descendant->value > edge->value) descendant->left = edge->left;
			else descendant->right = edge->left;
			delete edge;
		}
		else
		{
			if (descendant->value > edge->value) descendant->left = edge->right;
			else descendant->right = edge->right;
			delete edge;
		}
		return 1;//удаление успешно
	}
	if (key < edge->value)
		if (!edge->left)
			return 0; //нет элемента с таким ключом
		else
			deleteNode(key, edge->left, edge);
	else
		if (!edge->right)
			return 0; //нет элемента с таким ключом
		else
			deleteNode(key, edge->right, edge);
}