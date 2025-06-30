// ✅ Best Approach for This Problem: Two Pointers (Odd/Even)
// You can solve this with two pointers:

// odd pointer to build the list of odd-indexed nodes

// even pointer to build the list of even-indexed nodes

// Then, connect the end of the odd list to the start of the even list.



#include<bits/stdc++.h>
using namespace std;
 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(!head || head->next == 0) {
            return head;
        }
        ListNode* l1 = head;
        ListNode* l2 = head->next;
        ListNode* storedHead = l2; // Yeh maine node ko store krne ke liye use kiya h kynki main jb sbko odd or even ko merge karenge tb odd wala ek saath ho jaayega aur even wla lost ho jaayega 
        while(l2 && l2->next) {
            l1->next = l2->next;
            l2->next = l2->next->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        l1->next = storedHead;
        return head;
    }
};