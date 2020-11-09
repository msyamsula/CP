#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;
// typedef priority_queue<ii, vii, greater<ii>> pqi;
typedef queue<ii> qi;
vi min_d;

void sp(vvii graph, int start){
    int n = graph.size();
    min_d.assign(n, 1<<30);
    qi q; q.push({start,0});
    min_d[start]=0;

    while(!q.empty()){
        int u = q.front().first, d = q.front().second;
        q.pop();
        if (d > min_d[u]) continue;
        for(int i=0; i<graph[u].size(); i++){
            int v = graph[u][i].first, add = graph[u][i].second;
            if (d+add < min_d[v]){
                min_d[v] = d+add;
                q.push({v,min_d[v]});
            }
        }
    }
}

int main(){
    // vvii graph = {
    //     { {2,6}, {4,1} },
    //     { {2,2}, {3,3}, {4,6} },
    //     { {1,2}, {3,7}, {0,6} },
    //     { {1,3}, {2,7}, {4,5} },
    //     { {1,6}, {0,1}, {3,5} }
    // };

    int n,m; cin>>n>>m;
    vvii graph(n);
    for(int i=0; i<m; i++){
        int u,v,d; cin>>u>>v>>d;
        graph[u].push_back({v,d});
    }

    sp(graph, 2);
    for(int i=0; i<=4; i++){
        cout << min_d[i] << ' ';
    }
    cout << endl;

    return 0;
}