#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct Tree {
	int data;
	struct Tree* left;
	struct Tree* right;
}Tree;

void printTree(Tree* root) {
	if (root != NULL) {
		printTree(root->left);
		printTree(root->right);
		// visit
		printf("%d\n", root->data);
	}
	else {
		return;
	}
}

Tree* insertNode(Tree* root, int data) {
	if (root == NULL) { // No data on tree
		Tree* root = (Tree*)malloc(sizeof(Tree));
		root->data = data;
		root->left = NULL;
		root->right = NULL;
		return root;
	}
	else if (data <= (root->data)) {
		root->left = insertNode(root->left, data);
	}
	else if (data > (root->data)) {
		root->right = insertNode(root->right, data);
	}
	return root;
}

void Solve() {
	int data;
	Tree* root = NULL;
	while (scanf("%d", &data) != EOF) {
		// for debugging
		/*
		if (data == -1) {
			break;
		}
		*/
		root = insertNode(root, data);
	}
	printTree(root);
}

int main(void) {
	Solve();
	return 0;
}