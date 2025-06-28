#include <bits/stdc++.h>
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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL) {
            return head;
        }
        if(head->next == NULL) {
            return head;
        }
        ListNode* prev = head;
        ListNode* temp = head->next;
        while(temp != NULL) {
            //ab main find karoonga ki kahin nodes duplicates toh nhi
            if(temp->val == prev->val) {
                //duplicates h toh 
                prev->next = temp->next;
                temp->next = NULL;
                delete temp;
                temp = prev->next;
            }
            else {
                //duplicates nhi h toh 
                prev = prev->next;
                temp = temp->next;
            }
            temp = prev->next;
        }
        return head;
    }
};