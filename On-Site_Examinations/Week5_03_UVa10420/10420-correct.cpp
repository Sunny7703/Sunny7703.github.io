#include <iostream>
#include <map>
using namespace std;

int main()
{
    int t;
    cin >> t;

    map<string, int> m;
    string save[t];
    int i = 0;

    while(t--)
    {
        string country;
        cin >> country;
        save[i] = country;
        i++;
        cin.ignore();
        string name;
        getline(cin, name);
    }
    for (const string& s : save) {
        m[s]++;
    }

    for(auto p : m)
    {
        cout << p.first << " " << p.second << endl;
    }
}
