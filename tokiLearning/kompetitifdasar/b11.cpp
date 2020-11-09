#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<long long> vl;
typedef vector<vl> vvl;
typedef vector<string> vs;
typedef vector<vs> vvs;
typedef long long ll;
typedef pair<ll, ll> ii;
typedef pair<ii, ll> iii;
#define MAXLL (1ll<<60)
#define MAXI (1<<30)

vector<vector<ii>> graph;
vl dist;

vl bellman(){
    ll n = graph.size();
    dist.resize(0); dist.assign(n,MAXLL);
    dist[0]=0;
    for(ll r=0; r<n-1; r++){
        for(ll i=0; i<n; i++){
            ll u=i;
            for(ii temp : graph[u] ){
                ll v = temp.first, w = temp.second;
                ll newdis = dist[u]+w;
                dist[v] = min(dist[v], newdis);
            }
        }
    }

    return dist;
}

vvl small;
vl visited;
bool zc;
bool bellmanPass;

void dfs(ll u){
    visited[u]=1;
    for(ll v : small[u]){
        if (visited[v] == 0) dfs(v);
        else if (visited[v] == 1) zc = 1;
    }
}

void bellmanCheck(){
    ll n = graph.size();
    small.resize(0); small.resize(n);
    for(ll i=0; i<n; i++){
        ll u=i;
        for(ii temp : graph[u] ){
            ll v = temp.first, w = temp.second;
            ll newdis = dist[u]+w;
            if (newdis < dist[v]){
                // cout << u << ' ' << v << endl
                bellmanPass = 0;
                return;
            } else if (newdis == dist[v]){
                small[u].push_back(v);
            }
            dist[v] = min(dist[v], newdis);
        }
    }

    bellmanPass = 1;
}

void solve(){
    ll n, m; cin>>n>>m;
    graph.resize(0); graph.resize(n);
    for(ll i=0; i<m; i++){
        ll u,v,w; cin>>u>>v>>w;
        // u--; v--;
        graph[u].push_back({v,w});
    }

    // ll u = 0;
    // for(vector<ii> a : graph){
    //     for(ii b : a){
    //         cout << u << ' ' << b.first << ' ' << b.second << endl;
    //     }
    //     u++;
    // }
    
    bellman();
    // for(ll d : dist){
    //     cout << d << ' ';
    // }
    // cout << endl;
    bellmanPass = 0;
    bellmanCheck();
    if (bellmanPass){
        visited.resize(0); visited.assign(n, 0);
        zc = 0;
        // cout << zc << endl;
        dfs(0);
        // for(vl a : small){
        //     for(ll b : a){
        //         cout << b << ' ';
        //     }
        //     cout << endl;
        // }
        if (zc){
            cout << "Pak Dengklek tidak mau pulang" << endl;
        } else {
            if (dist[n-1] == MAXLL){
                cout << "Tidak ada jalan" << endl;
            } else {
                cout << dist[n-1] << endl;
            }
        }
    } else {
        cout << "Pak Dengklek tidak mau pulang" << endl;
    }
    // dist.resize(0); dist.assign(n,MAXLL);
    // dist[0]=0;
    // vl dist2 = bellman(1);

    // if (dist1 != dist2 ){
    //     cout << "Pak Dengklek tidak mau pulang" << endl;
    // } else if (dist2[n-1] == MAXLL){
    //     cout << "Tidak ada jalan" << endl;
    // } else {
    //     cout << dist2[n-1] << endl;
    // }
    //     // cout << dist[n-1] << endl;

    

}

int main(){
    ll tc; cin>>tc;
    for(ll i=0; i<tc; i++){
        // cout << "Case #" << i+1 << ": ";
        solve();
    }

    return 0;
}
