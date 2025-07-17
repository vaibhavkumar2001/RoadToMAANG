// Morris Inorder Traversal: Step-by-Step Algorithm
// Step 1: Initialize
// Let curr = root

// Step 2: Traverse the tree
// While curr != NULL:

// If curr.left == NULL

// Visit curr (i.e., print(curr.val))

// Move to the right: curr = curr.right

// If curr.left != NULL

// Find the inorder predecessor of curr, i.e., the rightmost node in curr.left subtree (pre)

// pre = curr.left

// While pre.right != NULL && pre.right != curr:
// pre = pre.right

// After finding pre:

// If pre.right == NULL

// Make a temporary link: pre.right = curr

// Move to the left: curr = curr.left

// If pre.right == curr

// (This means we've already visited left subtree)

// Remove the temporary link: pre.right = NULL

// Visit curr: print(curr.val)

// Move to the right: curr = curr.right


#include<bits/stdc++.h>
using namespace std;
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
    vector<int> inorderTraversal(TreeNode* root) {
        //main pehle ek vector banaoonga jisme main apne answer store karoonga
        vector<int>ans;
        //ab main ek curr variable banaoonga
        TreeNode* curr = root;
        //jb tk curr h toh main left pe jaaonga
        while(curr) {
            if(curr->left == nullptr) {
                //agr curr ka left h toh main ans mein push karoonga curr element ko 
                ans.push_back(curr->val);
                curr = curr->right;
            }
            //left node is not null;
            else {
                TreeNode* pred = curr->left;
                while(pred->right != curr && pred->right) {
                    //pred ka right curr ke equal nhi h aur pred right h toh 
                    pred = pred->right;
                }
                if(pred->right == nullptr) {
                    pred->right = curr;
                    curr = curr->left;
                }
                else {
                    pred->right = nullptr;;
                    //agr pred ka right null h toh main pred->right ko unlink karoonga
                    ans.push_back(curr->val);
                    curr = curr->right;
                }
            }
        }
        return ans;
    }
};