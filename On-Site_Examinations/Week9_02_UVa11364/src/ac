#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    
    int n, x[20];
    while(t--)
    {
        int max = 0;
        int min = 99;
        
        cin >> n;
        for(int i = 0; i < n; i++)
        {
            cin >> x[i];
        }
        
        for(int i = 0; i < n; i++)
        {
            if(x[i] > max)
                max = x[i];
            if(x[i] < min)
                min = x[i];
        }
        
        cout << (max - min) * 2 << endl;
    }
    return 0;
}
