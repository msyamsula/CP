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

map<string, vs> graph;
map<string, int> in;
map<string, int> visited;
map<string, string> parent;
deque<string> line;
vs toposort;

void dfs(string u){
    visited[u]=1;
    for(string v : graph[u]){
        if(visited[v]==0){
            parent[v] = u;
            dfs(v);
        }
    }
}

void backtrack(string v, string target){
    if (v=="" || v == target) return;
    line.push_front(parent[v]);
    backtrack(parent[v], target);
}

int main(){
    graph.clear();
    visited.clear();
    in.clear(); line.resize(0);
    int n,m; cin>>n>>m;
    for(int i=0; i<m; i++){
        string u,v; cin>>u>>v;
        graph[u].push_back(v);
        in[u] = in[u];
        in[v]++;
    }
    string a,b; cin>>a>>b;
    // cout << endl;

    // for(pair<string ,vs> temp : graph){
    //     cout << temp.first << ": ";
    //     for(string a : temp.second){
    //         cout << a << ' ';
    //     }
    //     cout << endl;
    // }
    // cout << endl;

    // for(pair<string, string> temp : parent){
    //     cout << temp.first << ' ' << temp.second << endl;
    // }

    queue<string> q;
    for(pair<string, int> temp : in){
        // cout << temp.first << ' ' << temp.second << endl;
        if (temp.second == 0){
            q.push(temp.first);
            toposort.push_back(temp.first);
            // visited[temp.first] = 1;
        }
    }

    while(!q.empty()){
        string u=q.front(); q.pop();
        for(string v : graph[u]){
            in[v]--;
            if (in[v] == 0){
                q.push(v);
                // visited[v] = 1;
                toposort.push_back(v);
            }
        }
    }

    map<string, int> idx;
    for(string ans : toposort){
        idx[ans] = idx.size();
    }

    string old,young;
    if(idx[a] <= idx[b]){
        old = a;
        young = b;
    } else {
        old = b;
        young = a;
    }

    dfs(old);
    line.push_front(young);
    backtrack(young,old);
    for(string temp : line){
        if (temp == ""){
            cout << "TIDAK MUNGKIN" << endl; return 0;
        }
        cout << temp << endl;
    }
    return 0;
}
