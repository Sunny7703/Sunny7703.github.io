#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> c;

// can we cover all bottles with <= m containers, each holding <= cap?
bool ok(int cap)
{
    int groups = 1, cur = 0;
    for (int i = 0; i < n; i++)
    {
        if (c[i] > cap) return false; // a single bottle is already too big
        if (cur + c[i] > cap) { groups++; cur = 0; }
        cur += c[i];
        if (groups > m) return false;
    }
    return true;
}

int main()
{
    while (cin >> n >> m)
    {
        c.assign(n, 0);
        int lo = 0, hi = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> c[i];
            hi += c[i];                 // upper bound = sum of all (1 container)
            if (c[i] > lo) lo = c[i];   // lower bound = max single bottle
        }

        // binary search the smallest cap that works
        int ans = hi;
        while (lo <= hi)
        {
            int mid = lo + (hi - lo) / 2;
            if (ok(mid)) { ans = mid; hi = mid - 1; }
            else         { lo = mid + 1; }
        }
        cout << ans << "\n";
    }
    return 0;
}
