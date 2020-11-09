#include<bits/stdc++.h>
using namespace std;

typedef vector<string> vs;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef queue<int> qi;

int dr[] = {1,1,0,-1,-1,-1,0,1};
int dc[] = {0,1,1,1,0,-1,-1,-1};

void paint(vs &grid, int r, int c, char w){
    if (r<0 || r>grid.size() || c<0 || c>grid[0].size()) return;
    else if (grid[r][c] != '.') return;

    grid[r][c] = w;
    for(int i=0; i<8; i++){
        paint(grid, r+dr[i], c+dc[i], w);
    }
}

vi visited;
vi topsort;

void dfs(int start, vvi graph){
    visited.resize(graph.size());
    memset(&visited[0], 0, graph.size());
    visited[start] = 1;
    cout << start << endl;
    for(int i=0; i<graph[start].size(); i++){
        if (visited[graph[start][i]] == 0) dfs(graph[start][i], graph);
    }
    topsort.push_back(start);
}

bool bipartiteCheck(vvi graph, int start){
    int n = graph.size();
    vi state(n,-1);
    state[start] = 0;
    qi q; q.push(start);
    bool bipartite = 1;
    while(!q.empty()){
        int cn = q.front(); q.pop();
        for (int i=0; i<graph[cn].size(); i++){
            if (state[graph[cn][i]] == -1){
                state[graph[cn][i]] = 1-state[cn];
                q.push(graph[cn][i]);
            } else if ( state[graph[cn][i]] == state[cn]){
                bipartite = 0;
                break;
            }
        }
    }

    return bipartite;
}

int main(){
    vvi graph = {
        {1,3},
        {2,0},
        {1,3},
        {2,0}
    };
    
    // dfs(0, graph);
    cout << bipartiteCheck(graph, 0) << endl;
    
    return 0;
}