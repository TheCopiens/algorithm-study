#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

/*
 Topic: 이진탐색트리 C 구현 
 Writer: JmKanmo
 Date: 2020.01.31
*/

struct BS_Tree
{
	int key;
	BS_Tree* left;
	BS_Tree* right;
};

BS_Tree* root;

BS_Tree* makeNode(int key) {
	BS_Tree* node = (BS_Tree*)malloc(sizeof(BS_Tree));
	node->key = key;
	node->left = NULL;
	node->right = NULL;
	return node;
}

void insertNode(int key)
{
	if (root == NULL)
	{
		root = makeNode(key);
	}
	else
	{
		BS_Tree* ptr = root;

		while (true)
		{
			if (key == ptr->key) {
				cout << "중복된 키는 삽입불가" << endl;
				return;
			}
			else {
				if (key < ptr->key)
				{
					if (ptr->left == NULL) {
						ptr->left = makeNode(key);
						break;
					}
					else {
						ptr = ptr->left;
					}
				}
				else
				{
					if (ptr->right == NULL) {
						ptr->right = makeNode(key);
						break;
					}
					else {
						ptr = ptr->right;
					}
				}
			}
		}
	}
}

bool searchNode(int key)
{
	BS_Tree* ptr = root;

	while (ptr != NULL)
	{
		int node_key = ptr->key;

		if (node_key < key)
		{
			ptr = ptr->right;
		}
		else if (node_key > key)
		{
			ptr = ptr->left;
		}
		else
		{
			return true;
		}
	}
	return false;
}

void clearNode(BS_Tree* ptr) 
{
	if (!ptr) return;
	clearNode(ptr->left);
	clearNode(ptr->right);
	free(ptr);
}

int deleteNode(int key)
{
	int ret = 2e9;
	BS_Tree* prev = root;
	BS_Tree* next = prev;


	while (next != NULL)
	{
		if (next->key == key)
		{
			if (!next->left && !next->right)
			{
				BS_Tree* del = next;
								
				break;
			}
			else
			{
				if (!next->left || !next->right)
				{

				}
				else
				{

				}
			}
		}
		else
		{
			if (next->key < key)
			{
				prev = next;
				next = next->right;
			}
			else
			{
				prev = next;
				next = next->left;
			}
		}
	}
	return ret;
}

int main()
{
	insertNode(25);
	insertNode(15);
	insertNode(100);
	insertNode(80);
	insertNode(45);
	clearNode(root);
	return 0;
}