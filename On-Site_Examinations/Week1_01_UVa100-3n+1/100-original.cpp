#include <iostream>
using namespace std;

int algorithm(int n)
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

        if(j < i)
            swap(i,j);

        int max = 0;
        for(int k = i; k <= j; k++)
        {
            if(algorithm(k) > max)
                max = algorithm(k);
        }

        cout << max << endl;
    }
    return 0;
}
