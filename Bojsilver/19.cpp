#include<iostream>
#include<stdlib.h>

using namespace std;

struct Node {
	char data;
	Node* left = nullptr;
	Node* right = nullptr;
};

Node* find(Node* root, char a)
{
	if (root == nullptr)
		return nullptr;
	if (root->data == a)
		return root;
	auto found = find(root->left, a);
	if (found) return found;
	found = find(root->right, a);
	if (found) return found;
	return nullptr;
}
void insertleft(Node* root, char a, char b)
{
	if (root == nullptr && b != '.') //·çÆ®°¡ ÅÖºó°æ¿ì ³ëµå Ã¤¿öÁÜ 
	{
		auto node = new(Node);
		root = node;
		root->data = b;
		return;
	}
	auto k = find(root, a);
	if (k->left == nullptr && b != '.') //¿ÞÂÊ ÀÚ½ÄÀÌ ºó °æ¿ì
	{
		auto node = new(Node);
		k->left = node;
		k->left->data = b;
	}
}
void insertright(Node* root, char a, char b)
{
	if (root == nullptr && b != '.') //·çÆ®°¡ ÅÖºó°æ¿ì ³ëµå Ã¤¿öÁÜ 
	{
		auto node = new(Node);
		root = node;
		root->data = b;
		return;
	}
	auto k = find(root, a);
	if (k->right == nullptr && b != '.') //¿À¸¥ÂÊ ÀÚ½ÄÀÌ ºó °æ¿ì
	{
		auto node = new(Node);
		k->right = node;
		k->right->data = b;
	}
}
void pretraversal(Node* root)
{
	if (root == nullptr)
		return;
	cout << root->data;
	pretraversal(root->left);
	pretraversal(root->right);
}
void intraversal(Node* root)
{
	if (root == nullptr)
		return;
	intraversal(root->left);
	cout << root->data;
	intraversal(root->right);
}
void posttraversal(Node* root)
{
	if (root == nullptr)
		return;
	posttraversal(root->left);
	posttraversal(root->right);
	cout << root->data;
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	Node* root = nullptr;
	char node, temp1, temp2;
	for (int i = 0; i < n;)
	{
		cin >> node >> temp1 >> temp2;
		insertleft(root, node, temp1);
		insertright(root, node, temp2);
	}
	pretraversal(root);
	cout << '\n';
	intraversal(root);
	cout << '\n';
	posttraversal(root);



}