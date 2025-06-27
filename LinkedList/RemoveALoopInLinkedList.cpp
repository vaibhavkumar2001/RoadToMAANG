#include<iostream>
using namespace std;
struct Node
{
    int data;
    Node* next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};
class Solution {
public:
    // Function to remove a loop in the linked list.
    void removeLoop(Node* head) {
        if (head == NULL || head->next == NULL) return;

        Node* slow = head;
        Node* fast = head;

        // Step 1: Detect loop using Floyd’s Cycle Detection
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) break;  // Loop detected
        }

        // No loop found
        if (fast == NULL || fast->next == NULL) return;

        // Step 2: Find starting point of the loop
        slow = head;

        // Special case: Loop starting at head
        if (slow == fast) {
            while (fast->next != slow) {
                fast = fast->next;
            }
        } else {
            while (slow->next != fast->next) {
                slow = slow->next;
                fast = fast->next;
            }
        }

        // Step 3: Remove the loop
        fast->next = NULL;
    }
};
