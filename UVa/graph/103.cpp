#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef tuple<long, vi, int> ivil;
typedef vector<ivil> vivil;
typedef vector<vi> vvi;

vvi graph;
vi parent;
vi d;

void bfs(vi start){
    int n = graph.size();
    d.assign(n, 0);
    parent.assign(n,-1);
    queue<int> q;
    for(int num : start){
        q.push(num);
    }
    while(!q.empty()){
        int u = q.front(); q.pop();
        cout << u << endl;
        for(int v : graph[u]){
            if (parent[v] == -1 || parent[v] != u){
                if(d[u]+1 > d[v]) parent[v] = u;
                // parent[v] = u;
                d[v] = max(d[v], d[u]+1);
                q.push(v);
            }
        }
    }
}

void solve(int k, int n){
    graph.resize(0);
    graph.resize(k);
    vivil data(k);
    for(int i=0; i<k; i++){
        int u = i;
        vi temp(n);
        long area = 1;
        for(int j=0; j<n; j++){
            cin>>temp[j];
            area *= temp[j];
        }
        sort(temp.begin(),temp.end());
        data[i] = {area,temp,u};
    }

    sort(data.begin(),data.end());
    vi indegree(k, 0);
    for(int i=0; i<k-1; i++){
        for(int j=i+1; j<k; j++){
            int u = get<2>(data[i]), v = get<2>(data[j]);
            bool pass = 1;
            for(int ii=0; ii<n; ii++){
                if (get<1>(data[i])[ii] > get<1>(data[j])[ii]){
                    pass = 0;
                    break;
                }
            }
            if (pass){
                graph[u].push_back(v);
                indegree[v] += 1;
            }
        }
    }

    // cout << "GRAPH" << endl;
    // for(vi temp: graph){
    //     for(int num : temp){
    //         cout << num << ' ';
    //     }
    //     cout << endl;
    // }

    vi u_start;
    for(int i=0; i<indegree.size(); i++){
        if (indegree[i] == 0) u_start.push_back(i);
    }

    bfs(u_start);
    int longestPath = -1;
    int u_end;
    for(int i=0; i<d.size(); i++){
        if (longestPath < d[i]){
            longestPath = d[i];
            u_end = i;
        }
    }

    // for(int num : d){
    //     cout << num << ' ';
    // }
    // cout << endl;

    stack<int> result;
    int u = u_end;
    // cout << u << endl;
    // for(int num : parent){
    //     cout << num << ' ';
    // }
    // cout << endl;

    while(u != -1){
        // cout << u << endl;
        result.push(u);
        u = parent[u];
    }
    // cout << "tes" << endl;
    // cout << "longest path = " 
    cout << longestPath+1 << endl;
    while(!result.empty()){
        cout << result.top()+1 << ' ';
        result.pop();
    }
    cout << endl;

    // for(int num : indegree){
    //     cout << num << ' ';
    // }
    // cout << endl;

    // for(ivil a : data){
    //     cout << get<0>(a) << ", ";
    //     for(int num : get<1>(a)){
    //         cout << num << ' ';
    //     }
    //     cout << ", " << get<2>(a);
    //     cout << endl;
    // }

    
}

int main(){
    int k,n;
    while(cin>>k>>n){
        // cout << "k n " << k << ' ' << n << endl;
        solve(k,n);
    }

    return 0;
}