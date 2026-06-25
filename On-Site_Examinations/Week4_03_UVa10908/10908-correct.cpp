#include <iostream>
#include <string>
using namespace std;

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int M, N, Q;
        cin >> M >> N >> Q;

        string g[105];
        for (int i = 0; i < M; i++)
            cin >> g[i];

        while (Q--)
        {
            int r, c;
            cin >> r >> c;

            char ch = g[r][c];
            int k = 0;

            // grow the square outward; check the new ring is in bounds and all == ch
            while (true)
            {
                int nk = k + 1;
                if (r - nk < 0 || r + nk >= M || c - nk < 0 || c + nk >= N) break;

                bool ok = true;
                for (int i = r - nk; i <= r + nk && ok; i++)
                    if (g[i][c - nk] != ch || g[i][c + nk] != ch) ok = false;
                for (int j = c - nk; j <= c + nk && ok; j++)
                    if (g[r - nk][j] != ch || g[r + nk][j] != ch) ok = false;

                if (!ok) break;
                k = nk;
            }
            cout << 2 * k + 1 << endl;
        }
    }
    return 0;
}
