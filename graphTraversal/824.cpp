#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

void solve(int px, int py, int d){
    // cout << px << endl;
    vi row(3,1);
    vvi grid(3,row);
    int norx = px-1, nory = py - 1;
    for (int i=0; i<8; i++){
        int tx; cin>>tx;
        int ty; cin>>ty;
        cin >> grid[2-ty+nory][tx-norx];
    }

    for (int i=0; i<3; i++){
        for (int j=0; j<3;j++){
            cout << grid[i][j] << ' ';
        }
        cout << endl;
    }

    int dx[] = {0,-1,-1,-1,0,1,1,1}, dy[] = {-1,-1,0,1,1,1,0,-1};
    // int dx[] = {0,1,1,1,0,-1,-1,-1}, dy[] = {-1,-1,0,1,1,1,0,-1};

    int cix = 1+dx[d], ciy = 1+dy[d];

    if (grid[ciy][cix] == 0){
        for (int i=d+1; i<d+8; i++){
            int ii = i%8;
            int nix = 1+dx[ii], niy = 1+dy[ii];
            if (grid[niy][nix] != grid[ciy][cix]){
                // ii = (ii-1 == -1) ? 7 : ii-1;
                cout << ii << endl;
                return;
            }
        }
    } else {
        for (int subs=1; subs<8; subs++){
            // cout << subs << endl;
            int ii = (d-subs);
            ii = (ii < 0) ? 8+ii : ii;
            int nix = 1+dx[ii], niy = 1+dy[ii];
            if (grid[niy][nix] != grid[ciy][cix]){
                ii = (ii+1)%8;
                cout << ii << endl;
                return;
            }
        }
    }
}

int main(){
    int px,py,d;
    while(cin>>px){
        if (px == -1) break;
        cin>>py>>d;
        solve(px, py, d);
    }

    return 0;
}