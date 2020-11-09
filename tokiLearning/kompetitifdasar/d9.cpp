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
#define MAXI (1ll<<30)

vvl graph;
vi visited;
vi dist;

void bfs(int start){
    visited[start] = 1;
    queue<int> q; q.push(start);

    while(!q.empty()){
        int u = q.front(); q.pop();
        for(int v : graph[u]){
            if (visited[v] == 0){
                visited[v] = 1;
                dist[v] = dist[u]+1;
                q.push(v);
            }
        }
    }
}

int main(){
    int n,l,t,start,end; cin>>n>>l>>t>>start>>end;
    start--; end--;
    graph.resize(0); graph.assign(n, vl(n,MAXI));
    // visited.resize(0); visited.assign(n,0);
    // dist.resize(0); dist.assign(n,0);
    for(int i=0; i<l; i++){
        int u,v; cin>>u>>v;
        u--; v--;
        graph[u][v] = 1;
        graph[v][u] = 1;
        // graph[u].push_back(v);
        // graph[v].push_back(u);
    }
    for(int i=0; i<n; i++){
        graph[i][i] = 0;
    }

    for(int k=0; k<n; k++){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                graph[i][j] = min(graph[i][j], graph[i][k]+graph[k][j]);
            }
        }
    }

    // for(vl temp : graph){
    //     for(ll a : temp){
    //         cout << a << ' ';
    //     }
    //     cout << endl;
    // }
    ll minim = graph[start][end];
    // cout << minim << endl;
    for(int i=0; i<t; i++){
        int bu,bv; cin>>bu>>bv;
        bu--; bv--;
        minim = min(minim, graph[start][bu]+graph[bv][end]+1);
        minim = min(minim, graph[start][bv]+graph[bu][end]+1);
    }

    cout << minim << endl;
    // start--;
    // end--;
    // bfs(start);
    // cout << dist[end] << endl;
    return 0;
}
