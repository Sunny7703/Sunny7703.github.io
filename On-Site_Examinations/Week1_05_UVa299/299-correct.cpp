#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    while(n--)
    {
        int l;
        cin >> l;
        int t[50];
        for(int i = 0; i < l; i++)
        {
            cin >> t[i];
        }

        int s = 0;
        for(int i = 0; i < l; i++)
        {
            for(int k = i + 1; k < l; k++)
            {
                if(t[i] > t[k])
                {
                    swap(t[i], t[k]);
                    s++;
                }
            }
        }

        cout << "Optimal train swapping takes " << s << " swaps." << endl;
    }
}
