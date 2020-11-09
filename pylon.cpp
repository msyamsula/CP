#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef tuple<int, int, int> iii;
typedef map<iii, int> dpt;

dpt mem;

int dp(vvi grid, int r, int c, int move, dpt &mem){
    iii key = make_tuple(r,c,move);
    if (mem.find(key) != mem.end()){
        // cout << "memo" << endl;
        return mem.at(key);
    }
    // cout << "calculation" << endl;
    grid[r][c] = 1;
    move++;
    if (move == grid.size()*grid[0].size()) return mem[key] = 1;

    int ans = 0;
    for(int i=0; i<grid.size(); i++){
        for(int j=0; j<grid[0].size(); j++){
            if (grid[i][j] == 1) continue;
            if (i == r || j==c || i-j == r-c || i+j == r+c) continue;
            // cout << i << ' ' << j << endl;
            ans += dp(grid, i, j, move, mem);
            if (ans > 0) return mem[key] = ans;
        }
    }

    return mem[key] = ans;
}

void solve(){
    int r,c; cin>>r>>c;
    vi zeros(c,0);
    vvi grid(r, zeros);
    // int ans;
    for(int i=0; i<r; i++){
        for (int j=0; j<c; j++){
            dpt mem;
            int ans = dp(grid,i,j,0,mem);
            if (ans > 0){
                cout << "POSSIBLE" << endl;
                return;
            }
        }
    }

    cout << "IMPOSSIBLE" << endl;
}

int main(){
    int tc; cin>>tc;
    for(int i=0; i<tc; i++){
        cout << "Case #" << i+1 << ": ";
        solve();
    }
    return 0;
}