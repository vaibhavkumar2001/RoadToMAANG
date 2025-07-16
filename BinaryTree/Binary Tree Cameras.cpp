// 968. Binary Tree Cameras

// You are given the root of a binary tree. We install cameras on the tree nodes where each camera at a node can monitor its parent, itself, and its immediate children.

// Return the minimum number of cameras needed to monitor all nodes of the tree.

// Example 1:

// Input: root = [0,0,null,0,0]
// Output: 1
// Explanation: One camera is enough to monitor all nodes if placed as shown.
// Example 2:

// Input: root = [0,0,null,0,null,0,null,null,0]
// Output: 2
// Explanation: At least two cameras are needed to monitor all nodes of the tree. The above image shows one of the valid configurations of camera placement.
 
// Constraints:

// The number of nodes in the tree is in the range [1, 1000].
// Node.val == 0

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
    int aageKeLiyeSolve(TreeNode* root,int& cameras) {
        if(!root) return 1;
        //ab main postorder perform karoonga
        //LRN -> Postorder
        //L
        int left = aageKeLiyeSolve(root->left,cameras);
        //R
        int right = aageKeLiyeSolve(root->right,cameras);
        //N
        if(left == 0 || right == 0) {
            cameras++;
            return 2;
        }
        if(left == 2 || right == 2) {
            return 1;
        }
        return 0;
    }
    int minCameraCover(TreeNode* root) {
        int cameras = 0;
        int RootSolve = aageKeLiyeSolve(root,cameras);
        if(RootSolve == 0) {
            cameras++;
        } 
        return cameras;
    }
};