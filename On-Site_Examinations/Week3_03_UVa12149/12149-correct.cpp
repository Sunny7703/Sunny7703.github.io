#include <iostream>
using namespace std;

int main()
{
    int n;
    while(cin >> n && n != 0)
    {
        int square = 0;
        for(int i = n; i > 0; i--)
        {
            square += i * i;
        }

        cout << square << endl;
    }
    return 0;
}

//n = 2
//(1x1) 4 + (2x2) 1 = 5

//n = 8
//(1x1) 64 + (2x2) 49 + ...
//(1x1) 8^2+ (2x2) 7^2+ ...
