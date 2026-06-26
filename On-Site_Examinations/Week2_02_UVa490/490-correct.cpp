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

    // pad all lines to maxLen
    for(auto& l : lines)
        while((int)l.size() < maxLen) l += ' ';

    // rotate 90 clockwise: column j becomes row j, read bottom to top
    int n = lines.size();
    for(int j = 0; j < maxLen; j++)
    {
        string row = "";
        for(int i = n - 1; i >= 0; i--)
            row += lines[i][j];
        // trim trailing spaces
        while(!row.empty() && row.back() == ' ') row.pop_back();
        cout << row << endl;
    }
    return 0;
}
