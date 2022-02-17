#include <iostream>
#include <vector>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    void reversePrintUitl(ListNode* node, vector<int>& vints) {
        if (node == NULL) return;
        reversePrintUitl(node->next, vints);
        vints.push_back(node->val);
    }
    vector<int> reversePrint(ListNode* head) {
        vector<int> ans;
        reversePrintUitl(head, ans);
        return ans;
    }
};