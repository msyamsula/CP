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

ll nc;
map<ll, vl> graph;
map<ll, ll> visited;
map<ll, ll> di;
set<ll> nodes;
ll start, ttl, tc;

void bfs(ll start){
    queue<ll> q; q.push(start);
    visited[start] = 1;
    di[start] = 0;
    while(!q.empty()){
        ll u = q.front(); q.pop();
        // if (di[u]>ttl) continue;
        for(ll v : graph[u]){
            if (di[v] > ttl) continue;
            if (visited[v] == 1) continue; 
            visited[v] = 1;
            di[v] = di[u]+1;
            if (di[v] <= ttl) q.push(v);
        }
    }
}

void solve(){
    bfs(start);
    ll cnt = 0;
    for(pair<ll, ll> p: di){
        ll num = p.second;
        ll key = p.first;
        // cout << key << ' ' << num << endl;
        if (num==-1 || num >ttl) cnt++;
    }

    cout << "Case " << tc << ": " << cnt << " nodes not reachable from node " << start << " with TTL = " << ttl << '.' << endl;
}

int main(){
    tc = 1;
    while(cin>>nc){
        if(!nc) break;
        graph.clear(); nodes.clear();
        // cout << "node size: " << nodes.size() << endl;
        // cout << "input: " << endl;
        for(ll i=0; i<nc; i++){
            ll u,v; cin>>u>>v;
            // cout << u << ' ' << v << endl;
            graph[u].push_back(v);
            graph[v].push_back(u);
            nodes.insert(u);
            nodes.insert(v);
        }
        
        while(cin>>start>>ttl){
            if(!start && !ttl) break;
            // visited.resize(0); visited.assign(nc+1, 0);
            // di.resize(0); di.assign(nc+1, MAXLL);
            visited.clear();
            di.clear();
            // cout << "nodes: " << endl;
            for(ll u : nodes){
                // cout << u << endl;
                di[u]=-1;
                visited[u]=0;
            }
            solve();
            tc++;
        }
    }

    return 0;
}
