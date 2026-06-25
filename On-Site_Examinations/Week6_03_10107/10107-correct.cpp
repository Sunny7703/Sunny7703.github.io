#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<long long> v;
    long long x;

    while (cin >> x)
    {
        // insert keeping the vector sorted (insertion-sort style)
        v.push_back(x);
        for (int i = (int)v.size() - 1; i > 0 && v[i] < v[i - 1]; i--)
            swap(v[i], v[i - 1]);

        int n = (int)v.size();
        long long mid;
        if (n % 2 == 1)
            mid = v[n / 2];                        // odd -> middle one
        else
            mid = (v[n / 2 - 1] + v[n / 2]) / 2;   // even -> integer average

        cout << mid << endl;
    }
    return 0;
}
