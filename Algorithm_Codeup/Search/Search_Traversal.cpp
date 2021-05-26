#include <iostream>
using namespace std;

typedef struct node* nodePointer;
typedef struct node {
	int data;
	nodePointer left, right;
} node;
void Preorder(nodePointer npt) {
	if (npt) {
		cout << npt->data << " ";
		Preorder(npt->left);
		Preorder(npt->right);
	}
}
void Inorder(nodePointer npt) {
	if (npt) {
		Inorder(npt->left);
		cout << npt->data << " ";
		Inorder(npt->right);
	}
}
void Postorder(nodePointer npt) {
	if (npt) {
		Postorder(npt->left);
		Postorder(npt->right);
		cout << npt->data << " ";
	}
}