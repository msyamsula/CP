#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef map<int, int> mii;
typedef queue<int> qi;

void APB(vvi graph, int u, int &counter, vi &low, vi &num, vi &parent, mii &cycle){
    low[u]=num[u]=counter;
    for(int i=0; i<graph[u].size(); i++){
        int v = graph[u][i];
        if (num[v] == -1){
            parent[v] = u;
            counter+=1;
            APB(graph, v, counter, low, num, parent, cycle);
            if (low[v]<=num[u]){
                cycle[u] = 1;
                cycle[v] = 1;
            }
            low[u] = min(low[u], low[v]);
        } else if (parent[u] != v) {
            low[u] = min(num[v], low[u]);
            cycle[u] = 1;
            cycle[v] = 1;
        }
    }
}

vi bfs(vvi graph, vi start){
    qi q;
    vi visited(graph.size(),0);
    vi bfs_length(graph.size(), 0);
    for (int i=0; i<start.size(); i++){
        q.push(start[i]);
        visited[start[i]] = 1;
    }

    while(!q.empty()){
        int u = q.front(); q.pop();
        for(int i=0; i<graph[u].size(); i++){
            int v = graph[u][i];
            if (visited[v] == 0){
                visited[v] = 1;
                q.push(v);
                bfs_length[v] = bfs_length[u] + 1;
            }
        }
    }

    return bfs_length;
}

void solve(int tc){
    int n; cin>>n;
    vvi graph(n+1);
    for (int i=0; i<n; i++){
        int u,v; cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    mii cycle;
    vi num(n+1, -1), low(n+1, -1), parent(n+1,-1);
    int counter = 0;
    APB(graph, 1, counter, low, num, parent, cycle);
    vi start;
    mii::iterator ii=cycle.begin();
    while(ii!=cycle.end()){
        start.push_back(ii->first);
        ii++;
    }

    cout << "Case #" << tc << ":";
    vi ans = bfs(graph, start);
    for (int i=1; i<ans.size(); i++){
        cout << ' ' << ans[i];
    }
    cout << endl;

}

int main(){
    int tc; cin>>tc;
    for(int i=0;i<tc;i++){
        solve(i+1);
    }

    return 0;
}