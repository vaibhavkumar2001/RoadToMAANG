#include<iostream>
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
    int getLength(ListNode* head) {
        int len = 0;
        ListNode* temp = head;
        while(temp != NULL) {
            len++;
            temp = temp->next;
        }
        return len;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL) {
            return head;
        }
        if(head->next == NULL) {
            return head;
        }
        int len = getLength(head);
        if(len < k) {
            return head;
        }
        ListNode* prev = NULL;
        ListNode* curr = head;
        int position = 0;
        while(position < k) {
            ListNode* forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
            position++;
        }
        if(curr != NULL) {
            ListNode* recursionKaHead = reverseKGroup(curr,k);
            head->next = recursionKaHead;
        }
        return prev;
    }
};