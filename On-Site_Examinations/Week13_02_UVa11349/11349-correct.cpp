#include <iostream>
#include <cstdio>
using namespace std;
int main(){
    int T; cin >> T;
    for(int t = 1; t <= T; t++){
        int n;
        scanf(" N = %d", &n);
        long long m[105][105];
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                scanf("%lld", &m[i][j]);
        bool sym = true;
        for(int i = 0; i < n && sym; i++)
            for(int j = 0; j < n && sym; j++){
                if(m[i][j] < 0) sym = false;
                if(m[i][j] != m[j][i]) sym = false;
            }
        printf("Test #%d: %s.\n", t, sym ? "Symmetric" : "Non-Symmetric");
    }
}
