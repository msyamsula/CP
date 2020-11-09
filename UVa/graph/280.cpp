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
vvl graph;
vl visited;
ll tot;

void bfs(ll start){
    queue<ll> q;
    q.push(start);

    while(!q.empty()){
        ll u=q.front(); q.pop();
        for(ll v : graph[u]){
            if (visited[v]==0){
                visited[v]=1;
                q.push(v);
                tot++;
            }
        }
    }
}

void solve(){
    graph.resize(0); graph.resize(n);
    ll u;
    while(cin>>u){
        if (u==0) break;
        u--;
        ll v;
        while(cin>>v){
            if(v==0) break;
            v--;
            graph[u].push_back(v);
        }
    }

    vl start; ll k; cin>>k;
    for(ll i=0; i<k; i++){
        ll temp; cin>>temp; temp--;
        start.push_back(temp);
    }

    // for(ll num : start){
    //     cout << num << ' ';
    // }
    // cout << endl;

    for(ll i=0; i<start.size(); i++){
        visited.resize(0); visited.assign(n, 0);
        tot = 0;
        bfs(start[i]);
        cout << n-tot;
        for(ll j=0; j<n; j++){
            if(visited[j]==0) cout << ' ' << j+1;
        }
        cout << endl;
    }
}

int main(){
    
    while(cin>>n)
    {
        if (n==0) break;
        // cout << "Case #" << i+1 << ": ";
        solve();
    }

    return 0;
}
