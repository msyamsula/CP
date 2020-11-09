#include<bits/stdc++.h>
using namespace std;
typedef map<char, string> mcs;
typedef map<char, char> mcc;
typedef map<char, int> mci;

void solve(string gr, char mp, char tp, int k){
    mcs graph;
    mcc dfs_parent;
    mci dfs_num;
    mci candle;
    stringstream ss(gr);
    string temp;
    while(getline(ss,temp,';')){
        // cout << temp << endl;
        dfs_num[temp[0]] = -1;
        dfs_parent[temp[0]] = '-';
        candle[temp[0]] = 0;
        if (temp.size() < 3){
            graph[temp[0]] = {};
        } else {
            graph[temp[0]] = temp.substr(2,temp.size());
        }
    }

    // mcs::iterator ii=graph.begin();
    // while(ii!=graph.end()){
    //     cout << ii->first << "-";
    //     string t = ii->second;
    //     string::iterator jj=t.begin();
    //     while(jj!=t.end()){
    //         cout << *jj;
    //         jj++;
    //     }cout << endl;
    //     ii++;
    // }
    char u = mp;
    // cout << u << ' ' << tp << endl;
    dfs_num[u] = 0;
    for (int move=0; move<(1<<30); move++){
        // cout << u << endl;
        int traped = 1;
        for (int i=0; i<graph[u].size(); i++){
            char v = graph[u][i];
            if (candle[v] == 1 || v==tp) continue;

            // int traped = 1;
            // for (int cc=0; cc<graph[v].size(); cc++){
            //     if (graph[v][cc] == u) continue;
            //     traped &= candle[graph[v][cc]];
            // }
            // if (traped){
            //     cout << "/" << v << endl;
            //     return;
            // }

            // if (dfs_num[v] == -1 || dfs_num[v] != dfs_num[u]-1){
                // cout << "visit " << v << endl;
            traped = 0;
            dfs_parent[v] = u;
            dfs_num[v] = dfs_num[u]+1;
            if (dfs_num[v]%k == 0){
                candle[u] = 1;
                cout << u << ' ';
            }
            tp = u;
            u = v;
            break;
            // }
        }
        if (traped) {
            cout << "/" << u <<endl;
            return;
        }
    }
}

int main(){
    string gr; char mp, tp; int k;
    while(cin>>gr){
        if (gr == "#") break;
        gr.erase(gr.size()-1);
        cin >> mp; cin>>tp; cin>>k;
        solve(gr, mp, tp, k);
    }

    return 0;
}