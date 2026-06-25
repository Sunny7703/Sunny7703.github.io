#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int M, N;
        scanf("%d %d", &M, &N);

        vector<int> a(M), u(N);
        for (int i = 0; i < M; i++) scanf("%d", &a[i]);
        for (int i = 0; i < N; i++) scanf("%d", &u[i]);

        // lower = max-heap holding the i smallest seen so far
        // upper = min-heap holding the rest
        priority_queue<int> lower;
        priority_queue<int, vector<int>, greater<int>> upper;

        int added = 0;
        for (int q = 0; q < N; q++)
        {
            // ADD elements up to u[q]
            while (added < u[q])
            {
                int x = a[added++];
                if (!lower.empty() && x > lower.top()) upper.push(x);
                else lower.push(x);
            }

            int wantSize = q + 1; // i-th GET wants i-th smallest
            while ((int)lower.size() < wantSize) { lower.push(upper.top()); upper.pop(); }
            while ((int)lower.size() > wantSize) { upper.push(lower.top()); lower.pop(); }

            printf("%d\n", lower.top());
        }
        if (T) printf("\n"); // blank line BETWEEN test cases (not after the last)
    }
    return 0;
}
