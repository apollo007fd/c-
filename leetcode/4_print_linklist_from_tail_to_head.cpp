#include <iostream>
#include <vector>
#include <functional>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    // 递归法，递归函数是匿名函数
    vector<int> reversePrint(ListNode* head) {
        vector<int> ans;
        std::function<void(ListNode*)> glambda;
        glambda = [&ans, &glambda] (ListNode* node) {  // 匿名函数递归需要函数本身的引用捕获
            if (node == NULL) return;
            glambda(node->next);
            ans.push_back(node->val);
        };
        glambda(head);
        return ans;
    }
};

int main() {
    ListNode* head = new ListNode(1);
    auto* node = head;
    for(int i = 2; i<5; ++i) {
        node->next = new ListNode(i);
        node = node->next;
    }
    Solution solu;
    auto ans = solu.reversePrint(head);
    for(auto i : ans)
        cout << i << endl;
}