#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef map<ii, int> miii;
#define INF 1<<30

vi parent;
int f;
vvii graph;
miii Edges;

void minFlow(int n, int mf, int s){
    int u = parent[n], v = n;
    cout << u << ' ' << v << endl;
    if (v == s) {f = mf; return;}
    else if (parent[n] != -1){
        int minimum = min(mf, Edges.at({u,v}));
        minFlow(u, minimum, s);
        Edges.at({u,v}) -= f;
        // Edges[{v,u}] += f;
    }
} 

int edmondKarp(int s, int t){
    int mf = 0;
    int n = graph.size();
    // for(int i=0; i<1; i++)
    while(1){
        f = 0;
        parent.assign(n, -1);
        // parent[s] = -1;
        queue<int> q; q.push(s);
        while(!q.empty()){
            int u = q.front(); q.pop();
            // cout << u << ' ' << endl;
            if (u == t) break;
            for(ii temp : graph[u]){
                int v = temp.first; 
                // int w;
                // try{
                //     w = Edges.at({u,v});
                // } catch (const exception &e){
                //     continue;
                // }
                // cout << v << endl;
                if (parent[v] == -1 && Edges.at({u,v}) > 0){
                    parent[v] = u;
                    q.push(v);
                }
            }
        }

        minFlow(t, INF, s);
        if ( f == 0) break;
        mf += f;
    }
    return mf;
}

int main(){
    int n,m; cin>>n>>m;
    graph.resize(n);
    for(int i=0; i<m; i++){
        int u, v, w; cin>>u>>v>>w;
        graph[u].push_back({v,w});
        ii key = {u,v};
        Edges[key] = w;
    }

    int s,t; cin>>s>>t;

    // for(vii temp : graph){
    //     for(ii vw : temp){
    //         int v = vw.first, w = vw.second;
    //         cout << v << '-' << w << ' ';
    //     }
    //     cout << endl;
    // }
    cout << edmondKarp(0,1) << endl;

    for(pair<ii, int> p : Edges){
        int u = p.first.first, v = p.first.second, w = p.second;
        cout << u << ' ' << v << ' ' << w << endl;
    }

    return 0;
}