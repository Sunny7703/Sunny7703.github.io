#include <iostream>
#include <set>
using namespace std;

int main()
{
    int n;
    while (scanf("%d", &n) == 1 && n != 0)
    {
        multiset<long long> s;
        long long sum = 0;

        for (int day = 0; day < n; day++)
        {
            int k;
            scanf("%d", &k);
            for (int j = 0; j < k; j++)
            {
                long long x;
                scanf("%lld", &x);
                s.insert(x);
            }

            // pick the max bill and the min bill -> add (max - min) to total
            auto it_lo = s.begin();
            auto it_hi = prev(s.end());
            sum += *it_hi - *it_lo;

            s.erase(it_hi);
            s.erase(s.begin());
        }
        printf("%lld\n", sum);
    }
    return 0;
}
