#include <iostream>
#include <string>
using namespace std;
int main(){
    int T; cin >> T;
    for(int t = 1; t <= T; t++){
        int n; cin >> n;
        string s; cin >> s;
        int count = 0;
        for(int i = 0; i < n; i++){
            if(s[i] == '.'){
                count++;
                i += 2; // covers i-1, i, i+1 -> skip next 2
            }
        }
        cout << "Case " << t << ": " << count << endl;
    }
}
