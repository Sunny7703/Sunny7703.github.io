#include <iostream>
using namespace std;

int algorithm(long long n)
{
    int count = 1;
    while(n != 1)
    {
        if(n % 2 == 1)
            n = 3 * n + 1;
        else
            n = n / 2;
        count++;
    }

    return count;
}

int main()
{
    int i = 0, j = 0;

    while(cin >> i >> j)
    {
        cout << i << " " << j << " ";

        int a = i, b = j;
        if(a > b) swap(a, b);

        int mx = 0;
        for(int k = a; k <= b; k++)
        {
            int len = algorithm(k);
            if(len > mx) mx = len;
        }

        cout << mx << endl;
    }
    return 0;
}
