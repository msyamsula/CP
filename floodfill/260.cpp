#include<bits/stdc++.h>
using namespace std;

typedef vector<string> vs;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

void dfs(vs grid, ii pos, vi &visited, int n, vi &w_col){
    int ix = pos.second, iy = pos.first;
    int idx = iy*n+ix;
    visited[idx] = 1;
    int dx[] = {-1,-1,0,0,1,1}, dy[] = {-1,0,-1,1,1,0};
    for (int i=0; i<6; i++){
        int nix = ix+dx[i], niy = iy+dy[i];
        if (nix<0 || nix>=n || niy<0 || niy>=n) continue;
        if (grid[niy][nix] == 'w' && visited[niy*n+nix] == 0){
            ii temp = {niy, nix};
            dfs(grid, temp, visited, n, w_col);
            w_col[nix] = 1;
        }
    }
}

void solve(int tc, int n){
    vs grid(n);
    vii w_start;
    vi w_col(n,0);
    for (int i=0; i<n;i++){
        cin >> grid[i];
        if (grid[i][0] == 'w'){
            w_start.push_back({i,0});
            w_col[0] = 1;
        }
    }

    if (w_start.size() == 0){
        cout << tc << ' ' << 'B' << endl;
        return;
    }

    vi visited(n*n, 0);
    for (int i=0; i<w_start.size(); i++){
        int idx = w_start[i].first*n+w_start[i].second;
        if (visited[idx] == 0) dfs(grid, w_start[i], visited, n, w_col);
    }

    for(int i=0; i<w_col.size(); i++){
        // cout << w_col[i] << ' ';
        if (w_col[i] == 0){
            cout << tc << ' ' << 'B' << endl;
            return;
        }
    } 
    // cout << endl;

    cout << tc << ' ' << 'W' << endl;
}

int main(){
    int n, tc=1;
    while(cin>>n){
        if (n==0) break;
        solve(tc, n);
        tc++;
    }

    return 0;
}