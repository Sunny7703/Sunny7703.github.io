#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n, m;
    while (cin >> n >> m && (n || m))
    {
        int dragon[2000], knight[2000];

        for (int i = 0; i < n; i++) cin >> dragon[i];
        for (int j = 0; j < m; j++) cin >> knight[j];

        sort(dragon, dragon + n); // ascending
        sort(knight, knight + m); // ascending

        int cost = 0, j = 0;
        bool ok = true;

        for (int i = 0; i < n; i++)
        {
            // find the cheapest knight that can handle this dragon
            while (j < m && knight[j] < dragon[i]) j++;
            if (j >= m) { ok = false; break; }
            cost += knight[j];
            j++; // this knight is used up
        }

        if (ok)
            cout << cost << endl;
        else
            cout << "Loowater is doomed!" << endl;
    }
    return 0;
}
