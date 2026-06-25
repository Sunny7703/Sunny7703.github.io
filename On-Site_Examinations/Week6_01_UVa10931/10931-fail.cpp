#include <iostream>
using namespace std;

int main()
{
    int I;
    while(cin >> I && I != 0)
    {
        int one = 0;
        cout << "The parity of ";
        for(int i = 30; i >= 0; i--)
        {
            if(I >= pow(2, i))
            {
                cout << "1";
                I -= pow(2, i);
                one++;
            }
            else if(I < pow(2, i) && i != 0)
                cout << "0";
        }

        cout << " is " << one << " (mod 2). " << endl;
    }
    return 0;
}
