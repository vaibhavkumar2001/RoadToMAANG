#include<bits/stdc++.h>
using namespace std;
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};


class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == NULL) return nullptr;

        // Step 1: Create new nodes and insert them next to original nodes
        Node* it = head;
        while (it) {
            Node* clonedNode = new Node(it->val);
            clonedNode->next = it->next;
            it->next = clonedNode;
            it = clonedNode->next;  // Move to the next original node
        }

        // Step 2: Assign random pointers for the cloned nodes
        it = head;  // Reset iterator to the start
        while (it) {
            Node* clonedNode = it->next;
            clonedNode->random = (it->random) ? it->random->next : nullptr;
            it = clonedNode->next;  // Move to the next original node
        }

        // Step 3: Detach the cloned list from the original list
        it = head;
        Node* clonedHead = head->next;  // This will be the head of the cloned list
        while (it) {
            Node* clonedNode = it->next;
            it->next = clonedNode->next;  // Restore original list
            if (clonedNode->next) {
                clonedNode->next = clonedNode->next->next;  // Move to the next cloned node
            }
            it = it->next;  // Move to the next original node
        }

        return clonedHead;
    }
};