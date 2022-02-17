#include <iostream>
#include <stack>
using namespace std;

class CQueue {
public:
    CQueue() {
    }
    
    void appendTail(int value) {
        sa.push(value);
    }

    int deleteHead() {
        if (!sb.empty()) {
            int ans = sb.top();
            sb.pop();
            return ans;
        }
        else if(sb.empty() && !sa.empty()) {
            while(!sa.empty()) {
                sb.push(sa.top());
                sa.pop();
            }
            int ans = sb.top();
            sb.pop();
            return ans;
        }
        //sb.empty() && sa.empty()
        return -1;
    }
private:
    std::stack<int> sa;
    std::stack<int> sb;
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */