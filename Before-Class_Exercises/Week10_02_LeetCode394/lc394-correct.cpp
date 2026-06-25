class Solution {
public:
    string decodeString(string s) {
        stack<string> strSt;
        stack<int> numSt;
        string cur = "";
        int num = 0;
        for (char c : s) {
            if (isdigit(c)) {
                num = num * 10 + (c - '0');
            } else if (c == '[') {
                strSt.push(cur);
                numSt.push(num);
                cur = "";
                num = 0;
            } else if (c == ']') {
                string tmp = strSt.top(); strSt.pop();
                int k = numSt.top(); numSt.pop();
                for (int i = 0; i < k; i++) tmp += cur;
                cur = tmp;
            } else {
                cur += c;
            }
        }
        return cur;
    }
};
