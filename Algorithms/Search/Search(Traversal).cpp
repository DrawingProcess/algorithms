#include <iostream>
using namespace std;

// Preorder Traversal: 1. 자신, 2. 왼쪽, 3. 오른쪽
// Inorder Traversal: 1. 왼쪽자신, 2. 자신, 3. 오른쪽
// Postorder Traversal: 1. 왼쪽, 2. 오른쪽, 3. 자신

int num = 15;
typedef struct node* treePointer;
typedef struct node {
	int data;
	treePointer leftChild, rightChild;
} node;

void preorder(treePointer ptr) {
	if (ptr) {
		cout << ptr->data << " ";
		preorder(ptr->leftChild);
		preorder(ptr->rightChild);
	}
}
void Inorder(treePointer ptr) {
	if (ptr) {
		Inorder(ptr->leftChild);
		cout << ptr->data << " ";
		Inorder(ptr->rightChild);
	}
}
void Postorder(treePointer ptr) {
	if (ptr) {
		Postorder(ptr->leftChild);
		Postorder(ptr->rightChild);
		cout << ptr->data << " ";
	}
}

int main() {
	node* nodes = new node[num + 1];
	for (int i = 1; i <= num; i++) {
		nodes[i].data = i;
		nodes[i].leftChild = NULL;
		nodes[i].rightChild = NULL;
	}
	for (int i = 1; i <= num; i++) {
		if (i % 2 == 0)
			nodes[i / 2].leftChild = &nodes[i];
		else
			nodes[i / 2].rightChild = &nodes[i];
	} 
	cout << "Preorder: ";
	preorder(&nodes[1]);
	cout << "\nInorder: ";
	Inorder(&nodes[1]);
	cout << "\nPostorder: ";
	Postorder(&nodes[1]);
}