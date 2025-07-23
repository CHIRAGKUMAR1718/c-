class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int ans1 = 0, ans2 = 0;
        stack<char> st1;
        for (char c : s) {
            if (!st1.empty() && st1.top() == 'a' && c == 'b') {
                st1.pop();
                ans1 += x;
            } else {
                st1.push(c);
            }
        }
        stack<char> temp1;
        while (!st1.empty()) {
            char c = st1.top(); st1.pop();
            if (!temp1.empty() && c == 'b' && temp1.top() == 'a') { 
                temp1.pop();
                ans1 += y;
            } else {
                temp1.push(c);
            }
        }
        stack<char> st2;
        for (char c : s) {
            if (!st2.empty() && st2.top() == 'b' && c == 'a') {
                st2.pop();
                ans2 += y;
            } else {
                st2.push(c);
            }
        }
        stack<char> temp2;
        while (!st2.empty()) {
            char c = st2.top(); st2.pop();
            if (!temp2.empty() && c == 'a' && temp2.top() == 'b') { 
                temp2.pop();
                ans2 += x;
            } else {
                temp2.push(c);
            }
        }
        return max(ans1, ans2);
    }
};
