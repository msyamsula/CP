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

ll N,E;
vvl graph;
set<vl> used_edges;

ll dfs(ll u){
    ll ans = 0;
    for(ll v : graph[u]){
        vl key = {u,v}; sort(key.begin(), key.end());
        if (used_edges.find(key) != used_edges.end()) continue;
        used_edges.insert(key);
        ans = max(ans, 1+dfs(v));
        used_edges.erase(key);
    }

    return ans;
}

void solve(){
    graph.resize(0); graph.resize(N);
    for(ll i=0; i<E; i++){
        ll u, v; cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    ll ans = 0;
    for(ll u=0; u<N; u++){
        ll cur_len = dfs(u);
        ans = max(ans, cur_len);
    }

    cout << ans << endl;
}

int main(){
    while(cin>>N>>E){
        if (!N && !E) break;
        solve();
    }
    // int tc; cin>>tc;
    // for(int i=0; i<tc; i++){
    //     cout << "Case #" << i+1 << ": ";
    //     solve();
    // }

    return 0;
}
