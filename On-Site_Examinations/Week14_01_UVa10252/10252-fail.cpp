#include <iostream>
#include <map>
using namespace std;

int main()
{
    string a;
    string b;

    while(cin >> a >> b)
    {
        map<char, int> m;

        for(int i = 0; i <= a.length(); i++)
        {
            for(int j = 0; j <= b.length(); j++)
            {
                if(a[i] == b[j])
                    m[a[i]]++;
            }
        }

        for(auto &p : m)
        {
            cout << p.first;
        }

        cout << endl;
    }
}
