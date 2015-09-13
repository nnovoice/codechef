#include <stdio.h>
#include <malloc.h>

struct TreeNode {
	TreeNode* left;
	TreeNode* right;
	//TreeNode* parent;
	int val;
};

const int MAX_NODES = 200001;
TreeNode* nodes[MAX_NODES];

void PrintNodes()
{
	for (int i = 0; nodes[i] != 0; ++i) {
		printf("D: %d ", nodes[i]->val);
	}
}

void TraverseTree(TreeNode* pHead, TreeNode* root)
{
	if (root->left != 0 && root->left != pHead) {
		TraverseTree(pHead, root->left);
	}

	printf("%d ", root->val);

	if (root->right != 0 && root->right != pHead) {
		TraverseTree(pHead, root->right);
	}
}

void TraverseTree(int rootVal)
{
	TreeNode* pHead = nodes[rootVal];
	TraverseTree(pHead, pHead);
}


int* GetEulerianPath(int val, int nodeVal1, int nodeVal2)
{
	return 0;
}

void UpdateTree(int nodeVal1, int nodeVal2)
{
	TreeNode* node1 = 0;
	TreeNode* node2 = 0;

	printf("D: nodes[nodeVal1]=%d ", nodes[nodeVal1]);
	printf("D: nodes[nodeVal2]=%d ", nodes[nodeVal2]);

	if (nodes[nodeVal1] != 0) {
		node1 = nodes[nodeVal1];
		printf("D: node1->right=%d ", node1->right);
		if (node1->right == 0) {
			node2 = (TreeNode*) malloc(1 * sizeof(TreeNode));
			node2->val = nodeVal2;

			node2->right = node1;
			node2->left = 0;

			node1->right = node2;

			nodes[nodeVal2] = node2;
		}
	}
	else if (nodes[nodeVal2] != 0) {
		node2 = nodes[nodeVal2];
		printf("D: node2->right=%d ", node2->right);
		if (node2->right == 0) {
			node1 = (TreeNode*) malloc(1 * sizeof(TreeNode));
			node1->val = nodeVal2;
			node1->right = node2;

			node2->right = node1;

			nodes[nodeVal1] = node1;
		}
	}
	else {
		node1 = (TreeNode*) malloc(1 * sizeof(TreeNode));
		node1->val = nodeVal1;

		node2 = (TreeNode*) malloc(1 * sizeof(TreeNode));
		node2->val = nodeVal2;

		//node1->parent = node2;
		node1->left = node2;
		node1->right = 0;

		//node2->parent = node1;
		node2->right = node1;
		node2->left = 0;

		nodes[nodeVal1] = node1;
		nodes[nodeVal2] = node2;
	}
}

int main()
{
	int nNodes = 0, nodeVal1 = 0, nodeVal2 = 0;
	int nQueries = 0, rootVal = 0;

	scanf ("%u", &nNodes);
	for (int i = 0; i < nNodes; ++i) {
		scanf ("%d %d", &nodeVal1, &nodeVal2);
		printf("D: u=%d v=%d\n", nodeVal1, nodeVal2);
		UpdateTree(nodeVal1, nodeVal2);
	}

	PrintNodes();

	scanf("%d", nQueries);

	for (int i = 0; i < nQueries; ++i) {
		scanf ("%d %d %d", &rootVal, &nodeVal1, &nodeVal2);
		printf("D: root=%d u=%d v=%d\n", rootVal, nodeVal1, nodeVal2);
		TraverseTree(rootVal);
	}

	return 0;
}
