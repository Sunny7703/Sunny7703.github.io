#include <iostream>
#include <map>
using namespace std;

int main()
{
    int t;
    cin >> t;

    map<string, int> m;

    while(t--)
    {
        string c, n;
        cin >> c;
        getline(cin, n);
        cin.ignore();
        m[c]++;
    }

    cout << << endl;
}
