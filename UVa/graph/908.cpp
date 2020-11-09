#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef tuple<long,long,long> iii;
typedef vector<iii> viii;
#define GET(i,temp) get<i>(temp)

viii edges;
vi ufd;

int parent(int u){
    if (ufd[u] < 0) return u;
    return parent(ufd[u]);
}

void join(int u, int v){
    int pu = parent(u), pv = parent(v);
    if (pu == pv) return;

    if (ufd[pu] <= ufd[pv]){
        ufd[pu] += ufd[pv];
        ufd[pv] = pu;
    } else {
        ufd[pv] += ufd[pu];
        ufd[pu] = pv;
    }
}

bool comp(iii a, iii b){
    return GET(2,a) < GET(2,b);
}


void solve(int n){
    // cout << n << endl;
    // cout << k << endl;
    edges.resize(0);
    ufd.assign(n+1, -1);
    long current = 0;
    for(int i=0; i<n-1; i++){
        long u,v,cost; cin>>u>>v>>cost;
        current+=cost;
    }
    int k; cin>>k;
    for(int i=0; i<k; i++){
        long u,v,cost; cin>>u>>v>>cost;
        edges.push_back({u,v,cost});
    }
    int m; cin>>m;
    for(int i=0; i<m; i++){
        long u,v,cost; cin>>u>>v>>cost;
        edges.push_back({u,v,cost});
    }
    sort(edges.begin(), edges.end(), comp);

    long minSpan = 0;
    for(iii temp : edges){
        // cout << GET(0,temp) << ' ' << GET(1,temp) << ' ' << GET(2,temp) << endl;
        int u = GET(0,temp), v = GET(1,temp);
        int pu = parent(u), pv = parent(v);
        if (pu == pv) continue;
        join(u,v);
        minSpan += GET(2,temp);
    }

    cout << current << endl;
    cout << minSpan << endl;

}

int main(){
    int n;
    int i=0;
    while(cin>>n){
        // cout << n << endl;
        if (i!=0) cout << endl;
        solve(n);
        i++;
    }

    return 0;
}