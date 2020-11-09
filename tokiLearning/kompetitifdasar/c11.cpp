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


vector<vector<ii>> graph;
vi dis;

void shortest(int start){
    int n=graph.size();
    dis.resize(0); dis.assign(n,MAXI);
    dis[start] = 0;
    queue<ii> q; q.push({start,0});

    while(!q.empty()){
        int u=q.front().first, d=q.front().second; q.pop();
        if (d>dis[u]) continue;
        for(ii temp : graph[u]){
            int v = temp.first, d = temp.second;
            int newdis = dis[u]+d;
            if (newdis < dis[v]){
                dis[v] = newdis;
                q.push({v,newdis});
            }
        }
    }
}

int main(){
    int n,m,q; cin>>n>>m>>q;
    graph.resize(n);
    for (int i=0; i<m; i++){
        int u,v,w; cin>>u>>v>>w;
        u--; v--;
        graph[u].push_back({v,w});
        graph[v].push_back({u,w});
    }

    vi query;
    for(int i=0; i<q; i++){
        int temp; cin>>temp;
        temp--;
        query.push_back(temp);
    }

    int mindis = 0;
    for(int i=0; i<q-1; i++){
        int u=query[i];
        int v=query[i+1];
        shortest(u);
        mindis += dis[v];
    }

    // for(int dist : dis){
    //     cout << dist << ' ';
    // }
    // cout << endl;

    cout << mindis << endl;

    return 0;
}
