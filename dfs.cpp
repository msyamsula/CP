#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef queue<int> qi;
typedef vector<string> vs;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef queue<ii> qii;
typedef deque<int> dqi;
typedef stack<int> sti;

void dfs(vvi graph, int node, vi &visited){
    visited[node] = 1;
    cout << node << endl;
    for (int i=0; i<graph[node].size(); i++){
        if (visited[graph[node][i]] == 0) dfs(graph, graph[node][i], visited);
    }
}

void bfs(vvi graph, vi nodes){
    qi q;
    vi visited(graph.size(), 0);
    for (int i=0; i<nodes.size(); i++){
        q.push(nodes[i]);
        visited[nodes[i]] = 1;
        cout << nodes[i] << endl;
    }

    while(!q.empty()){
        int top = q.front(); q.pop();
        for (int i=0; i<graph[top].size(); i++){
            if (visited[graph[top][i]] == 0){
                q.push(graph[top][i]);
                visited[graph[top][i]] = 1;
                cout << graph[top][i] << endl;
            }
        }
    }
}

void ucc(vvi graph, vi &visited){
    int ccCount = 0;
    for (int i=0; i<graph.size(); i++){
        if (visited[i] == 0){
            ccCount++;
            cout << "connected : " << ccCount << endl;
            dfs(graph, i, visited);
        }
    }
}

void ddrun(vs &grid, vii snode){
    int dc[] = {0,1,1,1,0,-1,-1,-1};
    int dr[] = {-1,-1,0,1,1,1,0,-1};
    int n=grid.size(), m=grid[0].size();
    qii q;
    vi visited(n*m, 0);
    for(int i=0; i<snode.size(); i++){
        int idx = snode[i].first * m + snode[i].second;
        q.push(snode[i]);
        visited[idx] = 1;
        cout << "visit : " << snode[i].first << ' ' << snode[i].second << endl;
        grid[snode[i].first][snode[i].second] = 'a';
    }

    while(!q.empty()){
        ii cell = q.front(); q.pop();
        int ci = cell.first, cj = cell.second;
        for (int i=0; i<8; i++){
            int cni = ci + dr[i], cnj = cj + dc[i];
            if (cni<0 || cni>=n || cnj<0 || cnj>=m) continue;
            if (grid[cni][cnj]=='#') continue; 
            if (visited[cni*m+cnj] == 0){
                visited[cni*m+cnj] = 1;
                q.push({cni, cnj});
                cout << "visit : " << cni << ' ' << cnj << endl;
                grid[cni][cnj]='a';
            }
        }
    }
    
}

sti ts;
void dfs2(vvi graph, int node, vi &visited){
    visited[node] = 1;
    for(int i=0; i<graph[node].size(); i++){
        if (visited[graph[node][i]] == 0) dfs2(graph, graph[node][i], visited);
    }
    ts.push(node);
}

bool biparcheck(vvi graph, int node){
    qi q;
    q.push(node);
    vi visited(graph.size(), 0);
    vi color(graph.size(), -1);
    color[node] = 0;
    visited[node] = 1;

    while(!q.empty()){
        int cn = q.front(); q.pop();
        for (int i=0; i<graph[cn].size(); i++){
            int nb = graph[cn][i];
            if (color[nb] == color[cn]) return 0;
            if (visited[nb] == 0){
                q.push(nb);
                visited[nb] = 1;
                color[nb] = 1 - color[cn];
            }
        }
    }

    return 1;
}

void kahn(vvi graph){
    vi indegree(graph.size(),0);
    for (int i=0; i<graph.size(); i++){
        for (int j=0; j<graph[i].size(); j++){
            indegree[graph[i][j]]++;
        }
    }

    vi topsort;
    vi visited(graph.size(),0);
    qi zi;
    for (int i=0; i<indegree.size(); i++){
        if (indegree[i] == 0){
            // visited[i] = 1;
            zi.push(i);
            topsort.push_back(i);
        }
    }

    while(!zi.empty()){
        int cn = zi.front(); zi.pop();
        // visited[cn] = 1;
        // topsort.push_back(cn);
        for (int i=0; i<graph[cn].size(); i++){
            int cnn = graph[cn][i];
            // if (visited[cnn] == 0){
            // visited[cnn] = 1;
            indegree[cnn]--;
            if (indegree[cnn] == 0){
                topsort.push_back(cnn);
                zi.push(cnn);
            }
            // }
        }
    }

    if (topsort.size() != graph.size()){
        cout << "no topsort" << endl;
        // return;
    }

    while(!topsort.empty()){
        cout << topsort[0] << ' ';
        topsort.erase(topsort.begin());
    } cout << endl;
}

int main(){
    vvi graph = {
        {2},
        {2},
        {3,1},
        {}
    };

    vs grid = {
        "#.#",
        "..#",
        "..."
    };

    

    // for (int i=0; i<indegree.size(); i++){
    //     cout << indegree[i] << ' ';
    // } cout << endl << endl;

    kahn(graph);

    return 0;
}
