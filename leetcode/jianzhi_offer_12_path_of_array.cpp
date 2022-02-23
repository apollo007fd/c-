#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (board.empty() || board[0].empty())
            return false;
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (dfs(board, i, j, word, 0))
                    return true;
            }
        }
        return false;
    }
    bool dfs(vector<vector<char>>& board, int i, int j, string word, int k) {
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || k < 0 || board[i][j] != word[k]) return false;
        if (k == word.size() - 1) return true;
        board[i][j] = ' ';
        vector<int> xi {i-1, i+1, i, i};
        vector<int> yi {j, j, j-1, j+1};
        bool ans = false;
        for (int l=0; l < xi.size(); ++l) {
            ans = ans || dfs(board, xi[l], yi[l], word, k+1);
        }
        board[i][j] = word[k];
        return ans;
    }
};

int main() {
    vector<vector<char>> board {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    string word = "ABCCED";
    Solution solution;
    cout << solution.exist(board, word) << endl;
}
