#include <iostream>
using namespace std;
int main(){
    int T; cin >> T;
    while(T--){
        int D, I; cin >> D >> I;
        int pos = 1;
        for(int d = 1; d < D; d++){
            if(I % 2 == 1) { pos = pos * 2; I = (I + 1) / 2; }
            else            { pos = pos * 2 + 1; I = I / 2; }
        }
        cout << pos << endl;
    }
}
