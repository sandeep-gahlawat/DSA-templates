#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node*left,*right;
    node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

node* sortedArrayToBST(int arr[], int start, int end)
{
	/* Base Case */
	if (start > end)
	return NULL;

	/* Get the middle element and make it root */
	int mid = (start + end)/2;
	node *root = new node(arr[mid]);

	/* Recursively construct the left subtree and make it
	left child of root */
	root->left = sortedArrayToBST(arr, start, mid-1);

	/* Recursively construct the right subtree and make it
	right child of root */
	root->right = sortedArrayToBST(arr, mid+1, end);

	return root;
}
