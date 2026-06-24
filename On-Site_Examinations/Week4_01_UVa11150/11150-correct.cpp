#include <iostream>
using namespace std;

int main()
{
    int n;
    while(cin >> n)
    {
        int total = n; // bottles drunk so far

        while (n >= 3)
        {
            total += n / 3; // new bottles received, drink them
            n = n / 3 + n % 3; // new empty bottles + leftover empty bottles
        }

        if (n == 2)
            total += 1; // borrow 1, able to return it

        cout << total << endl;
    }
    return 0;
}
