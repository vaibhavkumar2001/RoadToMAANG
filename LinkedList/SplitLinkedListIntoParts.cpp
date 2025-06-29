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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int len = 0;
        auto it = head;
        while(it) {
            len++;
            it = it->next;
        }
        int N = len;
        int partSize = N / k;
        int Extraspaces = N % k;
        vector<ListNode*>ans(k,nullptr);
        it = head;
        for(int i = 0;i < k && it;i++) {
            ans[i] = it;
            int currentSize = partSize +(Extraspaces-- > 0 ? 1 : 0);
            for(int j = 0;j < currentSize - 1;j++) {
                it = it->next;
            }
            auto nextpointer = it->next;
            it->next = nullptr;
            it = nextpointer;
        }
        return ans;    }
    };