#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n;
    while (cin >> n && n != 0)
    {
        string bin = "";
        int ones = 0;
        int tmp = n;
        while (tmp > 0)
        {
            int bit = tmp % 2;
            if (bit == 1) ones++;
            bin = (char)('0' + bit) + bin;
            tmp /= 2;
        }
        cout << "The parity of " << bin
             << " is " << ones
             << " (mod 2)." << endl;
    }
    return 0;
}
