// Transform to Sum Tree

// Given a Binary Tree of size N , where each node can have positive or negative values. Convert this to a tree where each node contains the sum of the left and right sub trees of the original tree. The values of leaf nodes are changed to 0.

// Example 1:

// Input:
//              10
//           /      \
//         -2        6
//        /   \     /  \
//      8     -4   7    5

// Output:
//             20
//           /    \
//         4        12
//        /  \     /  \
//      0     0   0    0

// Explanation:

//            (4-2+12+6)
//           /           \
//       (8-4)          (7+5)
//        /   \         /  \
//       0     0       0    0
 

// Your Task:  
// You dont need to read input or print anything. Complete the function toSumTree() which takes root node as input parameter and modifies the given tree in-place.

// Note: If you click on Compile and Test the output will be the in-order traversal of the modified tree.


// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(height of tree)
struct Node
{
    int data;
    Node* left, * right;
}; 

class Solution {
  public:

    // Convert a given tree to a tree where every node contains sum of values of
    // nodes in left and right subtrees in the original tree
    int sum(Node* root) {
        //Base Case likhoonga
        if(!root) return 0;
        if(!root->left && !root->right) {
            int temp = root->data;
            root->data = 0;
            return temp;
        }
        //Ab main apna postorder perform karoonga
        //LRN
        int leftSum = sum(root->left);
        int rightSum = sum(root->right);
        //ab main N wala kaam karoonga
        int temp = root->data;
        root->data = leftSum + rightSum;
        return root->data + temp;
    }
    void toSumTree(Node *node) {
        // Your code here
        sum(node);
    }
};