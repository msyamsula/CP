#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef queue<int> qi;


void dfs(vvi graph, int ix, int iy, int eix, int eiy, vi &visited, vi track){
    int idx = iy*graph[0].size()+ix;
    track.push_back(idx);
    if (ix==eix && iy==eiy){
        for (int i=0; i<track.size(); i++){
            cout << track[i] << ' ';
        }
        cout << endl;
        return;
    }

    // cout << eiy << ' ' << eix << ' ' << iy << ' ' << ix << ' ' << idx << endl;
    int n = graph.size(), m = graph[0].size();
    visited[idx] = 1;
    int dx[] = {-1,0,1,0}, dy[] = {0,-1,0,1};
    for (int i=0; i<4;i++){
        int nix = ix + dx[i], niy = iy + dy[i];
        if (nix<0 || nix>=m || niy<0 || niy>=n) continue;
        if ( (graph[iy][ix] == 3 || graph[iy][ix] == 1) && i==2 ) continue;
        if ( (graph[iy][ix] == 3 || graph[iy][ix] == 2) && i==3 ) continue;
        if ( (graph[niy][nix] == 3 || graph[niy][nix] == 1 ) && i==0 ) continue;
        if ( (graph[niy][nix] == 3 || graph[niy][nix] == 2) && i==1 ) continue;
        int nidx = niy*m+nix;
        if (visited[nidx] == 0) dfs(graph, nix, niy, eix, eiy, visited, track);
    }
}

void solve(int n, int m, int spx, int spy, int epx, int epy){
    vi row(m,0);
    vvi graph(n, row);
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            cin >> graph[i][j];
            // cout << graph[i][j] << ' ';
        }
        // cout << endl;
    }

    vi visited(n*m,0);
    vi track;
    dfs(graph, spx-1, spy-1, epx-1, epy-1, visited, track);
}

int main(){
    int tc = 0;
    int n,m,spx,spy,epx,epy;
    while(cin>>n>>m>>spy>>spx>>epy>>epx){
        if (!n && !m && !spx && !spy && !epx && !epy) break;
        tc++;
        // if (tc != 1) cout << endl;
        solve(n,m,spx,spy,epx,epy);
    }


    return 0;
}