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

vvi graph;
vi visited;
set<int> snodes;


int bfs(int start){
    int ans = 0;
    visited[start] = 1;
    queue<int> q; q.push(start);
    if (snodes.find(start) != snodes.end()) ans++;

    while(!q.empty()){
        int u = q.front(); q.pop();
        for(int v : graph[u]){
            if (visited[v] == 0){
                visited[v] = 1;
                q.push(v);
                if (snodes.find(v) != snodes.end()) ans++;
            }
        }
    }

    return ans;
}

void solve(){
    int n,e,q,r; cin>>n>>e>>q>>r;
    graph.resize(0); graph.resize(n);
    visited.resize(0); visited.assign(n,0);
    snodes.clear();
    vector<ii> edges;
    for(int i=0; i<e; i++){
        int u,v; cin>>u>>v;
        u--; v--;
        edges.push_back({u,v});
    }

    for(int i=0; i<q; i++){
        int u; cin>>u; u--;
        snodes.insert(u);
    }

    for(int i=0; i<r; i++){
        // cout << i << endl;
        int idx; cin>>idx; idx--;
        edges[idx] = {-1,-1};
    }
    // cout << "tes" << endl;

    for(ii temp : edges){
        if (temp.first == -1 && temp.second == -1) continue;
        int u = temp.first, v = temp.second;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    // int aa = 0;
    // for(vi temp : graph){
    //     cout << aa << ": ";
    //     for(int v : temp){
    //         cout << v << ' ';
    //     }
    //     cout << endl;
    //     aa++;
    // }

    vi scount;
    for(int i=0; i<n; i++){
        int u = i;
        if (visited[u] == 1) continue;
        scount.push_back(bfs(u));
    }

    int m = scount.size(); vi psum(m+1,0);
    for(int i=0; i<m; i++){
        psum[i+1] = psum[i]+scount[i];
    }

    // for(int a : psum){
    //     cout << a << endl;
    // }

    int tot = 0;
    for(int i=0; i<m; i++){
        tot += scount[i]*(psum[m]-psum[i+1]);
    }

    cout << tot << endl;
}

int main(){
    int tc; cin>>tc;
    for(int i=0; i<tc; i++){
        solve();
    }
    
    return 0;
}
