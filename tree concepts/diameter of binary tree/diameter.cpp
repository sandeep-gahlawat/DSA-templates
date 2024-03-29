
// C++ program to calculate Diameter of a Binary Tree
//The diameter of a tree is the number of nodes on the longest path between two leaves in the tree.
// Time Complexity: O(N2), where N is the number of nodes in the binary tree.
#include <bits/stdc++.h>
using namespace std;

// Binary Tree Node
struct node
{
    int data;
    struct node* left, *right;
};

// Function to create a new node of tree 
// and returns pointer 
struct node* newNode(int data);

// Function to Compute height of a tree
int height(struct node* node);

// Function to get diameter of a binary tree 
int diameter(struct node * tree)
{
    /* base case where tree is empty */
    if (tree == NULL)
        return 0;
    
    /* get the height of left and right sub-trees */
    int lheight = height(tree->left);
    int rheight = height(tree->right);
    
    /* get the diameter of left and right sub-trees */
    int ldiameter = diameter(tree->left);
    int rdiameter = diameter(tree->right);
    
    /* Return max of following three
    1) Diameter of left subtree
    2) Diameter of right subtree
    3) Height of left subtree + height of right subtree + 1 */
    return max(lheight + rheight + 1, max(ldiameter, rdiameter));
} 

/* UTILITY FUNCTIONS TO TEST diameter() FUNCTION */

/* The function Compute the "height" of a tree. Height is the 
    number f nodes along the longest path from the root node 
    down to the farthest leaf node.*/
int height(struct node* node)
{
    /* base case tree is empty */
    if(node == NULL)
        return 0;
    
    /* If tree is not empty then height = 1 + max of left 
        height and right heights */
    return 1 + max(height(node->left), height(node->right));
} 

/* Helper function that allocates a new node with the
   given data and NULL left and right pointers. */
struct node* newNode(int data)
{
    struct node* node = (struct node*)
                        malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    
    return(node);
}

// Driver Code
int main()
{

    /* Constructed binary tree is 
             1
            / \
           2   3
          / \
         4     5
    */
    struct node *root = newNode(1);
    root->left     = newNode(2);
    root->right     = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    
    cout<<"Diameter of the given binary tree is "<<diameter(root);

    return 0;
}



//diameter in O(n) time because only we have to calculate  left_height + right_height using global variable


int height(node* root, int& ans)
{
    if (root == NULL)
        return 0;
 
    int left_height = height(root->left, ans);
 
    int right_height = height(root->right, ans);
 
    // update the answer, because diameter of a
    // tree is nothing but maximum value of
    // (left_height + right_height ) for each node
    ans = max(ans,left_height + right_height);
 
    return 1 + max(left_height, right_height);
}
 
/* Computes the diameter of binary tree with given root. */
int diameter(node* root)
{
    if (root == NULL)
        return 0;
    int ans = INT_MIN; // This will store the final answer
    height(root, ans);
    return ans;
}