#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;

void alltopo(vvi adjList, vi &indegree, vi &visited, vi &toposort){
    bool flag = false;
    for(int u=0; u<adjList.size(); u++){
        if (indegree[u] == 0 && visited[u] == 0){
            visited[u] = 1;
            for(int v: adjList[u]){
                indegree[v]--;
            }
            toposort.push_back(u);
            alltopo(adjList, indegree, visited, toposort);
            visited[u] = 0;
            for(int v: adjList[u]){
                indegree[v]++;
            }
            toposort.erase(toposort.end()-1);

            flag = true;
        }
    }

    if (!flag){
        for(int u: toposort){
            cout << u << ' ';
        }
        cout << endl;
    }
}

vi kahn(vvi adjList, vi indegree){
    vi ans;
    queue<int> q;
    for(int i=0; i<indegree.size(); i++){
        if (indegree[i] == 0){
            q.push(i);
            ans.push_back(i);
        }
    }

    while(!q.empty()){
        int u = q.front(); q.pop();
        for(int v: adjList[u]){
            indegree[v]--;
            if (indegree[v] == 0){
                q.push(v);
                ans.push_back(v);
            }
        }
    }

    return ans;
}

int main(){
    int n,m; cin>>n>>m;
    vvi adjList(n);
    vi indegree(n,0);
    for(int i=0; i<m; i++){
        int u,v; cin>>u>>v;
        adjList[u].push_back(v);
        indegree[v] += 1;
    }

    vi visited(n,0);
    vi toposort;
    vi k = kahn(adjList, indegree);
    alltopo(adjList, indegree, visited, toposort);

    cout << endl;
    cout << "kahn toposort" << endl;
    for(int u : k){
        cout << u << ' ';
    }
    cout << endl;

    return 0;
}