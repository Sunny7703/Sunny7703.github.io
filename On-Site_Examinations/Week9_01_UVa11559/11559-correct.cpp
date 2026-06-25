#include <iostream>
using namespace std;

int main()
{
    int n, b, h, w;
    int p[20], a[20][15];

    while(cin >> n >> b >> h >> w)
    {
        int out = 0;

        for(int j = 0; j < h; j++)
        {
            cin >> p[j];

            for(int i = 0; i < w; i++)
            {
                cin >> a[j][i];
                if(a[j][i] >= n)
                {
                    int cost = p[j] * n;
                    if(cost <= b && (out == 0 || cost < out))
                        out = cost; // keeps the minimum
                }
            }
        }

        if(out != 0)
            cout << out << endl;
        else
            cout << "stay home" << endl;
    }
}
