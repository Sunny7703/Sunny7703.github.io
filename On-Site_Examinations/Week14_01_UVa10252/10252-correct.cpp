#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    string a, b;
    while(getline(cin, a) && getline(cin, b))
    {
        int ca[26] = {}, cb[26] = {};

        for(char c : a)
            ca[c - 'a']++; // char -> int
        for(char c : b)
            cb[c - 'a']++;

        for(int i = 0; i < 26; i++)
        {
            int times = min(ca[i], cb[i]);
            for(int j = 0; j < times; j++)
                cout << (char)('a' + i); // int -> char
        }
        cout << endl;
    }
}
