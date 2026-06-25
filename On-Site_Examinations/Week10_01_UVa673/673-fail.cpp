#include <iostream>
#include <string>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while(t--)
    {
        string s;
        cin >> s;

        bool balance = true;
        for(int i = 0; i < (int)s.length() - 1; i++)
        {
            for(int j = i; j < (int)s.length() - 2; j++)
            {
                if(s[i] == '(')
                {
                    balance = false;
                    if(s[j] == ')')
                    {
                        balance = true;
                        s[j] = '0';
                        break;
                    }
                }
                else if(s[i] == '[')
                {
                    balance = false;
                    if(s[j] == ']')
                    {
                        balance = true;
                        s[j] = '0';
                        break;
                    }
                }
            }
        }

        if(balance)
            cout << "Yes\n";
        else
            cout << "No\n";
    }
}
