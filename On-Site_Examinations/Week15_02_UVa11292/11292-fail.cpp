#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n, m;
    while (cin >> n >> m && n >= 1 && n <= 2000 && m >= 1 && m <= 2000)
    {
        if (n == 0 && m == 0) break;

        int dragon[2000], knight[2000];
        int max = 0, min = 2000;

        for (int i = 0; i < n; i++) cin >> dragon[i];
        for (int j = 0; j < m; j++) cin >> knight[j];

        // sort descending (wrong direction for min-cost)
        for (int i = 0; i < n; i++)
            for (int k = 0; k < n; k++)
                if (dragon[i] > dragon[k])
                    swap(dragon[i], dragon[k]);

        for (int j = 0; j < m; j++)
            for (int k = 0; k < m; k++)
                if (knight[j] > knight[k])
                    swap(knight[j], knight[k]);

        int o = 0;
        bool r = false;
        for (int i = 0; i < n; i++)
        {
            r = false;
            for (int j = 0; j < m; j++)
            {
                if (knight[j] >= dragon[i])
                {
                    o += knight[j];
                    knight[j] = 0;
                    r = true;
                    break;
                }
            }
        }

        if (m < n || o == 0 || !r)
            cout << "Loowater is doomed!" << endl;
        else
            cout << o << endl;
    }
}
