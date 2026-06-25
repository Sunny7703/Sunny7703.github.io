#include <iostream>
using namespace std;
int main()
{
    int t, n, x[20];
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(int i = 0; i < n; i++) cin >> x[i];
        int mx = 0, mn = 99;
        for(int i = 0; i < n; i++)
        {
            if(x[i] > mx) mx = x[i];
            if(x[i] < mn) mn = x[i];
        }
        cout << (mx - mn) << endl;
    }
    return 0;
}
