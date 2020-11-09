#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
typedef vector<pair<int,int>> vii;

vi ufd(100005,-1);

int find(int u){
    if (ufd[u] < 0) return u;
    return find(ufd[u]);
}

void join(int u, int v){
    int pu = find(u), pv = find(v);
    if (pu == pv) return;
    if (ufd[pu] <= ufd[pv]){
        ufd[pu] += ufd[pv];
        ufd[pv] = pu;
    } else if (ufd[pu] > ufd[pv]){
        ufd[pv] += ufd[pu];
        ufd[pu] = pv;
    }
}


void solve(){
    // memset(ufd, int(1), sizeof(ufd));
    ufd.assign(100005,-1);
    int n,m,clib,crod; cin>>n>>m>>clib>>crod;
    // for(int i=0; i<=n; i++){
    //     cout << ufd[i] << ' ';
    // }
    // cout << endl;
    int road = 0;
    for(int i=0;i<m;i++){
        int u,v; cin>>u>>v;
        int pu = find(u), pv = find(v);
        if (pu == pv){
            // cout << i << ' ' << pu << ' ' << pv << endl;
            continue;
        }
        join(u,v);
        road++;
        // ii e = make_pair(u,v);
        // edges.push_back(e);
    }

    int lib = 0;
    for(int i=1; i<=n; i++){
        if (ufd[i] < 0) lib++;
    }

    // for(int i=0; i<=n; i++){
    //     cout << ufd[i] << ' ';
    // }
    // cout <<endl;
    // cout << road << ' ' << lib << endl;

    int ans = min(n*clib, crod*road + clib*lib);
    cout << ans << endl;
}

int main(){
    int tc; cin>>tc;
    for(int i=0; i<tc; i++){
        solve();
    }

    return 0;
}