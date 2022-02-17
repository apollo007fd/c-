#include <iostream>
#include <vector>
using namespace std;

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* buildTreeHelper(const vector<int>& preorder, int i_pstart, const vector<int>& inorder, int i_istart, int c) {
        if (c <= 0) return NULL;
        if(c == 1) return new TreeNode(preorder[i_pstart]);
        // c > 1
        TreeNode* temp_head = new TreeNode(preorder[i_pstart]);
        int n = 0;
        while(n < c && preorder[i_pstart] != inorder[i_istart+n]) ++n;
        temp_head->left = buildTreeHelper(preorder, i_pstart+1, inorder, i_istart, n);
        temp_head->right = buildTreeHelper(preorder, i_pstart+n+1, inorder, i_istart+n+1, c-(n+1));
        return temp_head;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty()) return NULL;
        int size = preorder.size();
        TreeNode* head = new TreeNode(preorder[0]);
        int n = 0;
        while(inorder[n] != preorder[0]) {
            ++n;
        }
        head->left = buildTreeHelper(preorder, 1, inorder, 0, n);
        head->right= buildTreeHelper(preorder, n+1, inorder, n+1, size-(n+1));
        return head;
    }
};

int main() {
    return 0;
}