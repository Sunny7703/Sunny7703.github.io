#include <iostream>
using namespace std;
int main(){
    int n, m, caseNum = 0;
    while(cin >> n >> m && (n || m)){
        if(caseNum) cout << endl;
        caseNum++;
        char grid[105][105];
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                cin >> grid[i][j];
        cout << "Field #" << caseNum << ":" << endl;
        int dx[] = {-1,-1,-1,0,0,1,1,1};
        int dy[] = {-1,0,1,-1,1,-1,0,1};
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == '*'){ cout << '*'; continue; }
                int cnt = 0;
                for(int d = 0; d < 8; d++){
                    int ni = i+dx[d], nj = j+dy[d];
                    if(ni>=0 && ni<n && nj>=0 && nj<m && grid[ni][nj]=='*') cnt++;
                }
                cout << cnt;
            }
            cout << endl;
        }
    }
}
