#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{
    int t;
    cin >> t;
    cin.ignore(); // eat the newline after the number

    while (t--)
    {
        string s;
        getline(cin, s); // getline handles empty lines too

        stack<char> st;
        bool ok = true;

        for (int i = 0; i < (int)s.length() && ok; i++)
        {
            if (s[i] == '(' || s[i] == '[')
                st.push(s[i]);
            else if (s[i] == ')')
            {
                if (st.empty() || st.top() != '(') ok = false;
                else st.pop();
            }
            else if (s[i] == ']')
            {
                if (st.empty() || st.top() != '[') ok = false;
                else st.pop();
            }
        }

        if (ok && st.empty())
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}
