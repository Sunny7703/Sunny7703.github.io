#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    cin.ignore();

    int count[26] = {0};

    while(n--)
    {
        string s;
        getline(cin, s);

        for(int i = 0; i < s.length(); i++)
        {
            if(isalpha(s[i]))
                count[toupper(s[i]) - 'A']++;
        }
    }

    vector<pair<int,char>> res;
    for(int j = 0; j < 26; j++)
        if(count[j] != 0)
            res.push_back({count[j], (char)('A' + j)});

    sort(res.begin(), res.end(), [](auto& a, auto& b){
        if(a.first != b.first) return a.first > b.first;
        return a.second < b.second;
    });

    for(auto& p : res)
        cout << p.second << " " << p.first << endl;

    return 0;
}
