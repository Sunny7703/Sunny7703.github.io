#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
    int caseNum{};
    cin >> caseNum;

    for (int t = 0; t < caseNum; t++)
    {
        long long relativeNum{};
        cin >> relativeNum;

        vector<long long> streetNum(relativeNum);

        for (int i = 0; i < relativeNum; i++)
        {
            cin >> streetNum[i];
        }

        sort(streetNum.begin(), streetNum.end());

        long long median{};

        if (relativeNum % 2 == 1)
            median = streetNum[relativeNum / 2];
        else
            median = (streetNum[relativeNum / 2] + streetNum[relativeNum / 2 - 1]) / 2;

        long long totalDistance{};

        for (long long Vito : streetNum)
        {
            totalDistance += abs(Vito - median);
        }

        cout << totalDistance << endl;
    }

    return 0;
}
