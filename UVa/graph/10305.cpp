#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;

vvi graph;
vi ind;
vi visited;


void solve(int n, int m){
    graph.resize(0);
    graph.resize(n+1);
    ind.assign(n+1,0);
    visited.assign(n+1, 0);
    for(int i=0; i<m; i++){
        int u,v; cin>>u>>v;
        graph[u].push_back(v);
        ind[v]++;
    }

    queue<int> q;
    for(int i=1; i<=n; i++){
        if (ind[i] == 0){
            q.push(i);
            visited[i] = 1;
        }
    }

    vi order;
    while(!q.empty()){
        int u = q.front(); q.pop();
        order.push_back(u);
        for(int v : graph[u]){
            ind[v]--;
            if (ind[v] == 0){
                q.push(v);
            }
        }
    }

    if(order.size() != n){
        cout << "IMPOSSIBLE" << endl;
        return;
    }

    for(int i=0; i<order.size(); i++){
        cout << order[i] << " \n"[i==order.size()-1];
    }

}

int main(){
    int n,m;
    while(cin>>n>>m){
        if (n==0 && m==0) break;
        solve(n,m);
    }

    return 0;
}