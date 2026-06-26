#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    vector<string> lines;
    string s;
    int maxLen = 0;

    while(getline(cin, s))
    {
        lines.push_back(s);
        if((int)s.size() > maxLen) maxLen = s.size();
    }



    return 0;
}
