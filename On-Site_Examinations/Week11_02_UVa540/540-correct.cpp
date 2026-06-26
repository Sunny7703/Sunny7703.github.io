#include <iostream>
#include <queue>
#include <map>
using namespace std;
int main(){
    int t, caseNum = 0;
    while(cin >> t && t){
        caseNum++;
        cout << "Scenario #" << caseNum << endl;
        map<int, int> team;
        for(int i = 0; i < t; i++){
            int n; cin >> n;
            for(int j = 0; j < n; j++){
                int x; cin >> x;
                team[x] = i;
            }
        }
        queue<int> mainQ;
        queue<int> teamQ[1001];
        bool inMain[1001] = {};
        string cmd;
        while(cin >> cmd && cmd != "STOP"){
            if(cmd == "ENQUEUE"){
                int x; cin >> x;
                int tid = team[x];
                if(!inMain[tid]){ mainQ.push(tid); inMain[tid] = true; }
                teamQ[tid].push(x);
            } else {
                int tid = mainQ.front();
                cout << teamQ[tid].front() << endl;
                teamQ[tid].pop();
                if(teamQ[tid].empty()){ mainQ.pop(); inMain[tid] = false; }
            }
        }
        cout << endl;
    }
}
