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

ll n, min_edge;
ll s,t,c;
vvl graph;
map<pair<ll, ll>, ll> edges;
vl p;

void backtrack(ll v){
    ll u = p[v];
    if (u == -1 || u == -2) return;
    min_edge = min(min_edge, edges[{u,v}]);
    backtrack(u);
    edges[{u,v}] -= min_edge;
    edges[{v,u}] += min_edge;
}

void solve(){
    cin>>s>>t>>c;
    s--; t--;
    edges.clear();
    graph.resize(0); graph.resize(n);
    for(ll i=0; i<c; i++){
        ll u,v; cin>>u>>v;
        u--;v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
        ll w; cin>>w;
        edges[{u,v}] = w;
        edges[{v,u}] = w;
    }

    ll mf = 0;
    ll idx = 0;

    // cout << "graph: " << endl;
    // for(ll i=0; i<n; i++){
    //     for(ll num : graph[i]){
    //         cout << num << ' ';
    //     }
    //     cout << endl;
    // }

    // cout << "edges: " << endl;
    // for(pair<pair<ll, ll>, ll> p : edges){
    //     cout << p.first.first << ' ' << p.first.second << ": " << p.second << endl;
    // }

    while(1){
        // idx++;
        // cout << "idx: " << idx << endl;
        p.resize(0); p.assign(n, -2);
        p[s]=-1;
        
        // cout << endl;
        queue<ll> q; q.push(s);
        while(!q.empty()){
            ll u = q.front(); q.pop();
            // cout << "pop: " << u << endl;
            if (u==t) break;
            for(ll v : graph[u]){
                if (p[v] == -2 && edges[{u,v}]>0){
                    p[v] = u;
                    q.push(v);
                }
            }
        }

        min_edge = MAXLL;
        backtrack(t);
        // cout << "edges: " << endl;
        // for(pair<pair<ll, ll>, ll> edge : edges){
        //     cout << edge.first.first << ' ' << edge.first.second << ": " << edge.second << endl;
        // }
        // cout << "p: ";
        // for(ll num : p){
        //     cout << num << ' ';
        // }
        // cout << endl;

        // cout << min_edge << endl;
        if (min_edge == MAXLL) break;
        mf+=min_edge;
        if (idx==10) break;
    }

    cout << "The bandwidth is " << mf << endl;
}

int main(){
    ll tc = 1;
    while(cin>>n){
        if(!n) break;
        cout << "Network " << tc << endl;
        solve();
        tc++;
    }

    return 0;
}
