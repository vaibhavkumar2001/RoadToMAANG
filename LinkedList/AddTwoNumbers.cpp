#include <iostream>
using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* iterative(ListNode* l1, ListNode* l2) {
        ListNode* ans = new ListNode(-1);
        ListNode* it = ans;
        int carry = 0;
        while (l1 || l2 || carry) {
            int a = l1 ? l1->val : 0;
            int b = l2 ? l2->val : 0;
            int sum = a + b + carry;
            int digit = sum % 10;
            carry = sum / 10;
            it->next = new ListNode(digit);
            it = it->next;
            l1 = l1 ? l1->next : nullptr;
            l2 = l2 ? l2->next : nullptr;
        }
        ListNode* finalAns = ans->next;
        delete ans;
        return finalAns;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        return iterative(l1, l2);
    }
};

// Helper function to create a linked list from an array
ListNode* createList(int arr[], int n) {
    ListNode* head = new ListNode(arr[0]);
    ListNode* current = head;
    for (int i = 1; i < n; i++) {
        current->next = new ListNode(arr[i]);
        current = current->next;
    }
    return head;
}

// Helper function to print a linked list
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Solution sol;

    int arr1[] = {2, 4, 3}; // represents number 342
    int arr2[] = {5, 6, 4}; // represents number 465

    ListNode* l1 = createList(arr1, 3);
    ListNode* l2 = createList(arr2, 3);

    ListNode* result = sol.addTwoNumbers(l1, l2); // Should return 7 -> 0 -> 8

    cout << "Result: ";
    printList(result);

    return 0;
}
