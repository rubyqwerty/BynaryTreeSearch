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

int BynaryTreeSearch::min_elem_in_the_subtree(node* edge, node* descendant)
{
	if (!edge->left && !edge->right)
	{
		if (descendant->value < edge->value) descendant->right = nullptr;
		else descendant->left = nullptr;
		int n = edge->value;
		delete edge;
		return n;
	}
	if (!edge->left)
	{
		descendant->left = edge->right;
		int n = edge->value;
		delete edge;
		return n;
	}
	min_elem_in_the_subtree(edge->left, edge);
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
			edge->value = min_elem_in_the_subtree(edge->right, edge);
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

int BynaryTreeSearch::replace(int value1, int value2)
{
	if (!deleteNode(value1))
		return 0; // невозможно заменить элемент, так как нет такого элемента
	push(value2);
}

void BynaryTreeSearch::clear(node* edge)
{
	if (!edge) edge = root;
	if (!edge) return;
	if (edge->left)
		clear(edge->left);
	if (edge->right)
		clear(edge->right);
	delete edge;
}

void BynaryTreeSearch::bypassing(node* edge)
{
	if (!edge) edge = root;
	if (edge->left) bypassing(edge->left);
	cout << edge->value << " ";
	if (edge->right) bypassing(edge->right);
	
}