#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    string line;
    bool first = true;

    while (getline(cin, line))
    {
        int count[128] = {0};

        for (int i = 0; i < (int)line.length(); i++)
        {
            int ascii = (int)line[i]; // char -> ASCII value
            count[ascii]++;
        }

        vector<pair<int,int>> res; // (ascii, freq)
        for (int a = 32; a <= 126; a++)
            if (count[a] > 0)
                res.push_back({a, count[a]});

        sort(res.begin(), res.end(), [](auto& x, auto& y){
            if (x.second != y.second) return x.second < y.second; // freq asc
            return x.first > y.first;                              // tie: ascii desc
        });

        if (!first) cout << endl;   // blank line BETWEEN cases (not after the last)
        first = false;

        for (auto& p : res)
            cout << p.first << " " << p.second << endl;
    }
    return 0;
}
