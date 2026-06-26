#include <iostream>
#include <queue>
#include <map>
using namespace std;
int main(){
    int t, caseNum = 0;
    while(cin >> t && t){
        caseNum++;
        map<int, int> team;
        for(int i = 0; i < t; i++){
            int n; cin >> n;
            for(int j = 0; j < n; j++){
                int x; cin >> x;
                team[x] = i;
            }
        }



    }
}
