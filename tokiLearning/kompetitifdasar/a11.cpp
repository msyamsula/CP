#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<long long> vl;
typedef vector<vl> vvl;
typedef vector<string> vs;
typedef vector<vs> vvs;
typedef pair<int, int> ii;
typedef pair<int, long> il;
typedef pair<ii, int> iii;
typedef long long ll;
#define MAXLL (1ll<<60)
#define MAXI (1<<30)


vector<vector<il>> graph;
vl dis;

void shortest(int start){
    int n=graph.size();
    dis.resize(0); dis.assign(n, MAXLL);
    dis[start] = 0;
    queue<ii> q; q.push({start, 0});

    while(!q.empty()){
        int u = q.front().first;
        ll d = q.front().second;
        q.pop();
        if (d>dis[u]) continue;
        for(ii temp : graph[u]){
            int v = temp.first; ll w = temp.second;
            ll newdis = dis[u] + w;
            if (newdis < dis[v]){
                dis[v] = newdis;
                q.push({v,dis[v]});
            }
        }
    }
}

int main(){
    int n,m,a,b; cin>>n>>m>>a>>b;
    a--; b--;
    graph.resize(0); graph.resize(n);
    for(int i=0; i<m; i++){
        int u,v,w; cin>>u>>v>>w;
        u--; v--;
        graph[u].push_back({v,w});
        graph[v].push_back({u,w});
    }

    shortest(a);

    cout << dis[b] << endl;

    return 0;
}
