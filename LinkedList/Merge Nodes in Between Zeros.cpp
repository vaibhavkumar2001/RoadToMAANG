// 🧠 Where the Slow & Fast Pointer Intuition Comes In
// After reading the problem, the intuition to use two pointers (slow & fast) arises when you realize:

// You're scanning between two 0s.

// You want to collect a group of nodes, sum their values, and move on to the next group.

// So, one pointer can track the beginning of a group (just after a 0), and another can scan forward until it reaches the next 0.






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
    ListNode* mergeNodes(ListNode* head) {
        if(!head) return 0;
        ListNode* slow = head;
        ListNode* fast = head->next;
        ListNode* LastNode = 0;
        int sum = 0;
        while(fast) {
            if(fast->val != 0) {
                sum += fast->val;
            }
            else {
                slow->val = sum;
                LastNode = slow;
                sum = 0;
                slow = slow->next;
            }
            fast = fast->next;
        }
        //ab mera yahan ek main kaam toh bach hi gya ki main abhi tk saara consecutive ke beech ka sum toh calculate krke place kr diya pr mujhe toh modify linked list bhejna tha toh mera kaam abhi bacha h ki bachi hui linked list ko delete krna  h
        ListNode* temp = LastNode->next;
        LastNode->next = NULL;
        while(temp) {
            ListNode* next = temp->next;
            delete temp;
            temp = next;
        }
        return head;
    }
};




















