#include <iostream>
using namespace std;

int main()
{
    long long s;
    long long d;

    cin >> s >> d;


    long long sum = 0;
    while(sum < d)
    {
        sum += s;
        if(sum < d)
            s++;
    }

        cout << s << endl;
    }
    return 0;
}
