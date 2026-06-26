#include <iostream>
#include <stack>
using namespace std;
int main(){
    int n;
    while(cin >> n && n){
        int target;
        while(cin >> target && target){
            int a[1001]; a[0] = target;
            for(int i = 1; i < n; i++) cin >> a[i];
            stack<int> st;
            int idx = 0, next = 1;
            bool ok = true;
            while(idx < n){
                if(!st.empty() && st.top() == a[idx]){ st.pop(); idx++; }
                else if(next <= n){ st.push(next++); }
                else { ok = false; break; }
            }
            cout << (ok ? "Yes" : "No") << endl;
        }
        cout << endl;
    }
}
