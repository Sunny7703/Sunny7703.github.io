#include <iostream>
using namespace std;

int main()
{
    int n = 0;
    int caseNum = 1;
    while(cin >> n)
    {
        if(n < 2)
            break;

        int b[100] = {};
        for(int i = 0; i < n; i++)
        {
            cin >> b[i];
        }

        bool ok = true;

        // (forgot to check strictly increasing here)

        int sum[20005] = {};

        for(int i = 0; i < n && ok; i++)
        {
            for(int j = n - 1; j >= i; j--)
            {
                int s = b[i] + b[j];

                if(sum[s])
                {
                    ok = false;
                    break;
                }

                sum[s] = 1;
            }
        }

        cout << "Case #" << caseNum++;
        if(!ok)
            cout << ": It is not a B2-Sequence." << endl;
        else
            cout << ": It is a B2-Sequence." << endl;
        cout << endl;
    }

    return 0;
}
