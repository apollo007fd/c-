#include <iostream>
#include <vector>
using namespace std;

void sort(vector<int>& inputs, int beg, int end) {
    for (int i = beg; i <= end; ++i) {
        int i_min = i;
        for (int j = i+1; j <= end; ++j) {
            if (inputs[i_min] > inputs[j]) i_min = j;
        }
        int temp = inputs[i];
        inputs[i] = inputs[i_min];
        inputs[i_min] = temp;
    }
}

vector<int> remove_repeat(vector<int>& inputs) {
    vector<int> ans;
    if (inputs.empty()) return inputs;
    int begin = 0, end = 0;
    int size = inputs.size();
    while(begin < size) {
        int N = inputs[begin];
        if (N == 0) {
            ++begin;
            continue;
        }
        end = begin + N;
        ++begin;  // the first number
        sort(inputs, begin, end);
        // save without repeat
        int val = inputs[begin];
        ans.push_back(val);
        for (int i = begin+1; i <= end; ++i) {
            if (val != inputs[i]) {
                val = inputs[i];
                ans.push_back(val);
            }
        }
        begin = end + 1;
    }
    return ans;
}

int main() {
    string s;
    //vector<int> inputs{3, 2, 2, 1, 11, 10, 20, 40, 32, 67, 40, 20, 89, 300, 400, 15};
    vector<int> inputs;
    while(getline(cin, s)) {
        inputs.push_back(stoi(s));
    }
    vector<int> ans = remove_repeat(inputs);
    for (auto i : ans) 
        cout << i << endl;
}