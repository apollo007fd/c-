#include <iostream>
#include <unordered_map>
#include <cmath>
#include <vector>
using namespace std;

int max_value(vector<vector<int>>& inputs, int m, int s) {
    if (inputs.empty())
        return 0;
    int size = inputs.size();
    unordered_map<int, vector<int>> primers;
    unordered_map<int, vector<vector<int>>> secondarys;
    for (int i = 0; i < size; ++i) {
        if (inputs[i][2] == 0) {
            primers[i+1] = {inputs[i][0], inputs[i][1]};
        } else {
            int primer_i = inputs[i][2];
            if (secondarys.find(primer_i) == secondarys.end())  {
                vector<vector<int>> temp;
                secondarys[primer_i] = std::move(temp);
            }
            vector<int> temp{inputs[i][0], inputs[i][1]};
            secondarys[primer_i].push_back(std::move(temp));
        }
    }
    int n = primers.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    vector<vector<int>> w(n, vector<int>());
    vector<vector<int>> v(n, vector<int>());
    {
        int i = 0;
        for (unordered_map<int, vector<int>>::iterator iter = primers.begin(); iter != primers.end(); ++iter, ++i) {
            int id = iter->first;
            const vector<int>& content = iter->second;
            int w_tmp = content[0];
            int v_tmp = content[1] * w_tmp;
            w[i].push_back(w_tmp);
            v[i].push_back(v_tmp);
            for (int j = 0; j < secondarys[id].size(); ++j) {
                w[i].push_back(w_tmp + secondarys[id][j][0]);
                v[i].push_back(v_tmp + secondarys[id][j][0] * secondarys[id][j][1]);
                if (j == 1) {
                    w[i].push_back(w_tmp + secondarys[id][j-1][0] + secondarys[id][j][0]);
                    v[i].push_back(v_tmp + secondarys[id][j-1][0] * secondarys[id][j-1][1] + secondarys[id][j][0] * secondarys[id][j][1]);
                }
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 10; j <= m; j+=10) {
            int max_i = dp[i][j];
            for (int k = 0; k < w[i].size(); ++k) {
                if (j - w[i][k] >= 0) {
                    max_i = max(max_i, dp[i][j-w[i][k]] + v[i][k]);
                }
            }
            dp[i+1][j] = max_i;
        }
    }
    return dp[n][m];
}

vector<string> split(const string& str, const string& delim) {
    vector<string> ret;
    if (str.empty()) return ret;
    auto begin = 0U;
    auto end = str.find(delim);
    while (end != std::string::npos) {
        ret.push_back(str.substr(begin, end-begin));
        begin = end + delim.length();
        end = str.find(delim, begin);
    }
    if (begin < str.size()) ret.push_back(str.substr(begin, str.size()-begin));
    return ret;
}

int main() {
    int s=5, m=1000;
    vector<vector<int>> inputs;
    string ss;
    getline(cin, ss);
    const auto& ret = split(ss, " ");
    m = stoi(ret[0]);
    s = stoi(ret[1]);
    while(getline(cin, ss)) {
        vector<int> temp;
        const auto& ret = split(ss, " ");
        for (const auto& s : ret)
            temp.push_back(stoi(s));
        inputs.push_back(temp);
    }
    //vector<string> temp_ss = {"800 2 0", "400 5 1", "300 5 1", "400 3 0", "500 2 0"};
    //for (auto& s : temp_ss) {
    //    vector<int> temp;
    //    ss = s;
    //    const auto& ret = split(ss, " ");
    //    for (const auto& s : ret)
    //        temp.push_back(stoi(s));
    //    inputs.push_back(temp);
    //}
    //for(auto& is : inputs) {
    //    for (auto i : is)
    //        cout << i << " ";
    //    cout << endl;
    //}
    int ans = max_value(inputs, m, s);
    cout << ans << endl;
}