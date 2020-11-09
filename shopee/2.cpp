#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<long long> vl;
typedef vector<vl> vvl;
typedef vector<string> vs;
typedef vector<vs> vvs;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;
typedef long long ll;
#define MAXLL (1ll<<60)
#define MAXI (1<<30)

ll n;
vector<vector<pair<ll, ll>>> graph;
vl indegree;
ll d;
priority_queue<ll> pq;
// map<ll, ll> mem;

void dfs(ll start){
    // if (mem.find(start) != mem.end()){
    //     d+=mem[start];
    //     return;
    // }
    bool r=0;
    for(pair<ll, ll> p : graph[start]){
        ll v=p.first, w=p.second;
        d+=w;
        r=1;
        dfs(v);
        d-=w;
    }

    if(!r){
        pq.push(d);
    }
}


// vl ufd;
// vvl edges;

// ll parent(ll u){
//     if (ufd[u]<0) return u;
//     return parent(ufd[u]);
// }

// void join(ll u, ll v){
//     ll pu = parent(u), pv = parent(v);
//     if (pu == pv) return;

    // if (ufd[pu]<=ufd[pv]){
    //     ufd[pu]+=ufd[pv];
    //     ufd[pv]=pu;
    // } else {
    //     ufd[pv]+=ufd[pu];
    //     ufd[pu]=pv;
    // }
// }

// bool comp(vl a, vl b){
//     // cout << "tes" << endl;
//     if (a[2] != b[2]) return a[2]<b[2];
//     else if (a[0] != b[0]) return a[0]<b[0];

//     return a[1] < b[1];
// }

void solve(){
    cin>>n;
    // edges.resize(0);
    // ufd.resize(0); ufd.assign(n, -1);
    graph.resize(0); graph.resize(n);
    indegree.resize(0); indegree.assign(n, 0);
    for(ll i=0; i<n-1; i++){
        ll u,v,w; cin>>u>>v>>w;
        u--; v--;
        graph[u].push_back({v,w});
        indegree[v]++;
    }

    for(ll i=0; i<n; i++){
        if (indegree[i] == 0){
            d = 0;
            dfs(i);
        }
    }

    pq.pop();
    cout << pq.top() << endl;

    // sort(edges.begin(), edges.end(), comp);
    // cout << "tes" << endl;

    // ll ans = 0;
    // for(ll i=1; i<n-1; i++){
    //     ll u = edges[i][0], v = edges[i][1], w = edges[i][2];
    //     ll pu = parent(u), pv = parent(v);
    //     if (pu == pv) continue;
    //     cout << "edges: " << u+1 << ' ' << v+1 << ' ' << w << endl;
    //     ans += w;
    //     join(u, v);
    // }

    // cout << ans << endl;
}

int main(){
    solve();
    // int tc; cin>>tc;
    // for(int i=0; i<tc; i++){
    //     cout << "Case #" << i+1 << ": ";
    //     solve();
    // }

    return 0;
}
