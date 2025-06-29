#include <bits/stdc++.h>
using namespace std;
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};


class Solution {
public:
    Node* Solve(Node* head) {
        auto it = head;
        auto tail = head; // abhi agr glt hua toh main head ki jagah it rakhoonga
        while(it) {
            if(it->child) {
                //toh ab main tail tk traverse karoonga
                auto childTail = Solve(it->child); // tailNode
                //ab main flatten ka kaam karoonga
                auto temp = it->next;
                it->next = it->child;
                it->child->prev = it;
                childTail->next = temp;
                if(temp) {
                    temp->prev = childTail;
                }
                it->child = nullptr;
            }
            tail = it;
            it = it->next;
        }
        return tail;
    }
    Node* flatten(Node* head) {
        if(!head) {
            return nullptr;
        }
        Solve(head);
        return head;
    }
};