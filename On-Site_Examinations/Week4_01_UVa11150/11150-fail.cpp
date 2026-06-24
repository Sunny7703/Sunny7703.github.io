#include <iostream>
using namespace std;

int main()
{
    int n;
    while(cin >> n)
    {
        int total = n; // bottles drunk so far

        if (n % 3 == 2) // WRONG: decide borrow straight from n % 3
            total += 1;

        while (n >= 3)
        {
            total += n / 3; // new bottles received, drink them
            n = n / 3 + n % 3; // new empty bottles + leftover empty bottles
        }

        cout << total << endl;
    }
    return 0;
}
