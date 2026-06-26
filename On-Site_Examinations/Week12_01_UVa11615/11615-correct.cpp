#include <iostream>
using namespace std;
int main(){
    int T; cin >> T;
    while(T--){
        long long n, a, b;
        cin >> n >> a >> b;
        // find LCA in a complete binary tree (parent = x/2)
        while(a != b){
            if(a > b) a /= 2;
            else b /= 2;
        }
        // count nodes in LCA's subtree
        long long lca = a, cnt = 0;
        long long lo = lca, hi = lca;
        while(lo <= n){
            long long realHi = min(hi, n);
            cnt += realHi - lo + 1;
            lo *= 2;
            hi = hi * 2 + 1;
        }
        cout << n - cnt << endl;
    }
}
