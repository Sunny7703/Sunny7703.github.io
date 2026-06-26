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
            cin >> streetNum[i];



    }

    return 0;
}
