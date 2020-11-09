#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<long> vl;
typedef vector<vl> vvl;
typedef vector<string> vs;
typedef vector<vs> vvs;

vvi cur;
int dy[4] = {-1,0,1,0}, dx[4] = {0,1,0,-1};

void battle(int n){
    int r = cur.size(), c = cur[0].size();
    vvi temp = cur;
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            int heir = cur[i][j];
            for(int ii=0; ii<4; ii++){
                int ni=i+dy[ii], nj=j+dx[ii];
                if (ni<0 || ni>=r || nj<0 || nj>=c) continue;
                if (cur[ni][nj] == (heir+1)%n){
                    temp[ni][nj] = heir;
                }
            }
        }
    }

    cur = temp;
}

void solve(int n, int r, int c, int k){
    cur.resize(0);
    cur.assign(r, vi(c,-1));
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cin>>cur[i][j];
        }
    }

    for(int i=0; i<k; i++){
        battle(n);
    }

    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cout << cur[i][j] << " \n"[j==c-1];
        }
    }
}

int main(){
    int n,r,c,k;
    while(cin>>n>>r>>c>>k){
        if (!n && !r && !c && !k) break;
        // cout << "Case #" << i+1 << ": ";
        solve(n,r,c,k);
    }

    return 0;
}