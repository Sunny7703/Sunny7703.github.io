#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        vector<int> move(n + 1); // move[i] = +1 or -1 for instruction i
        int pos = 0;

        for (int i = 1; i <= n; i++)
        {
            string cmd;
            cin >> cmd;

            if (cmd == "LEFT")
                move[i] = -1;
            else if (cmd == "RIGHT")
                move[i] = 1;
            else // SAME AS k
            {
                string as;
                int k;
                cin >> as >> k; // read "AS" and the index k
                move[i] = move[k];
            }

            pos += move[i];
        }

        cout << pos << endl;
    }
    return 0;
}
