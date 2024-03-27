#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct Tree {
	int data;
	struct Tree* left;
	struct Tree* right;
}Tree;

void postOrderPrint(Tree* root) {
	if (root != NULL) {
		postOrderPrint(root->left);
		postOrderPrint(root->right);
		printf("%d\n", root->data);
	}
	else {
		return;
	}
}

Tree* insertNode(Tree* root, int data) {
	if (root == NULL) { // When the nodes locates
		Tree* root = (Tree*)malloc(sizeof(Tree));
		root->data = data;
		root->left = NULL;
		root->right = NULL;
		return root; 
	}

	if (data <= root->data) { // go to left tree
		root->left = insertNode(root->left, data);
	}
	else { // go to right tree
		root->right = insertNode(root->right, data);
	}
	return root;
}

void Solve() {
	int newData;
	Tree* root = NULL; // initially, root is NULL
	while (scanf("%d", &newData) != EOF) {
		/*
		if (newData == -1) {
			break;
		} -> for debugging
		*/
		root = insertNode(root, newData);
	}
	postOrderPrint(root);
}

int main(void) {
	Solve();
	return 0;
}