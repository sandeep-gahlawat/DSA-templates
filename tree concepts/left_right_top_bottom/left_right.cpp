

#include<bits/stdc++.h>
using namespace std;

// A Binary Tree Node
struct Node
{
	int data;
	struct Node *left, *right;
};

// Utility function to create a new tree node
Node* newNode(int data)
{
	Node *temp = new Node;
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}

// function to print left view of
// binary tree using levelorder traversal
void printLeftView(Node* root)
{
	if (!root)
		return;

	queue<Node*> q;
	q.push(root);

	while (!q.empty())
	{	
		// number of nodes at current level
		int n = q.size();
		
		// Traverse all nodes of current level
		for(int i = 1; i <= n; i++)
		{
			Node* temp = q.front();
			q.pop();
				
			// Print the left most element
			// at the level
			if (i == 1)
				cout<<temp->data<<" ";
			
			// Add left node to queue
			if (temp->left != NULL)
				q.push(temp->left);

			// Add right node to queue
			if (temp->right != NULL)
				q.push(temp->right);
		}
	}
}	

//using recursion
void leftViewUtil(struct Node* root, int level,
                  int* max_level)
{
    // Base Case
    if (root == NULL)
        return;
 
    // If this is the first Node of its level
    if (*max_level < level) {
        cout << root->data << " ";
        *max_level = level;
    }
 
    // Recur for left subtree first,
    // then right subtree
    leftViewUtil(root->left, level + 1, max_level);
    leftViewUtil(root->right, level + 1, max_level);
}
 
// A wrapper over leftViewUtil()
void leftView(struct Node* root)
{
    int max_level = 0;
    leftViewUtil(root, 1, &max_level);
}

// Driver code
int main()
{
	// Let's construct the tree as
	// shown in example

	Node* root = newNode(10);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(7);
	root->left->right = newNode(8);
	root->right->right = newNode(15);
	root->right->left = newNode(12);
	root->right->right->left = newNode(14);

	printLeftView(root);
}

// This code is contributed by
// Manne SreeCharan



//right side of veiw
  struct TreeNode {
      int val;
     TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
class Solution {
public:
     vector<int> sol;
    int level;
    void Traversal(TreeNode *root,int l){
        if(!root) return ;
        
        if(level==l){
            sol.push_back(root->val);
            level++;
        }
        
        Traversal(root->right,l+1);
        Traversal(root->left,l+1);
        
    }
    
    vector<int> rightSideView(TreeNode* root) {
        level = 0;
        sol.clear();
        Traversal(root,0);
        return sol;
    }
   
};