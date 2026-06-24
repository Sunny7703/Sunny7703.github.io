#include <iostream>
using namespace std;

int main()
{
    int s;
    long long d;
    while(cin >> s >> d)
    {
        long long sum = 0;
        while(sum < d)
        {
            sum += s;
            s++;
        }

        cout << s - 1 << endl;
    }
    return 0;
}
