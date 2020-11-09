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
vector<pair<ll, ll>> arr;
vl visited, dist;
vvl graph;

// bool comp(pair<ll, ll> a, pair<ll, ll> b){
//     if (a.first != b.first) return a.first < b.first;
//     return a.second < b.second;
// }

ll bfs(ll start){
    visited[start] = 1;
    dist[start] = 1;
    queue<ll> q; q.push(start);
    ll ans = 1;
    while(!q.empty()){
        ll u = q.front(); q.pop();
        for(ll v : graph[u]){
            if (visited[v] == 1) continue;
            visited[v] = 1;
            dist[v] = dist[u]+1;
            ans = max(dist[v], ans);
        }
    }

    return ans;
}

void dfs(ll u){
    dist[u] = max(1ll, dist[u]);
    for(ll v : graph[u]){
        dist[v] = max(dist[v], dist[u]+1);
        dfs(v);
    }
}

void solve(){
    cin>>n;
    arr.resize(0);
    for(ll i=0; i<n; i++){
        ll temp; cin>>temp;
        arr.push_back({temp, i+1});
    }
    // vector<pair<ll, ll>> arr_cpy = arr;
    // sort(arr_cpy.begin(), arr_cpy.end(), comp);
    graph.resize(0);
    graph.resize(n+1);
    for(ll i=0; i<n; i++){
        ll pidx = arr[i].second, value = arr[i].first;
        for(ll m=2; m*pidx<=n; m++){
            ll cidx = (m*pidx)-1;
            if (arr[cidx].first > value) graph[pidx].push_back(cidx+1);
        }
    }

    // cout << "graph: " << endl;
    // for(vl a : graph){
    //     for(ll num : a){
    //         cout << num << ' ';
    //     }
    //     cout << endl;
    // }

    visited.resize(0); dist.resize(0);
    visited.assign(n+1, 0); dist.assign(n+1, 0);
    for (ll i=0; i<n; i++){
        // if (visited[i] == 1) continue;
        dfs(i);
        // ll temp = bfs(i);
        // ans = max(ans, temp);
    }
    ll ans = -MAXLL;
    for(ll num : dist){
        ans = max(num, ans);
    }

    // cout << "ans: ";
    cout << ans << endl;

}

int main(){
    int tc; cin>>tc;
    for(int i=0; i<tc; i++){
        // cout << "Case #" << i+1 << ": ";
        solve();
    }

    // ll n = 100000;
    // double ans = 0;
    // for(ll i=1; i<=n; i++){
    //     ans += double(1)/i;
    // }
    // cout << ans << endl;

    return 0;
}
