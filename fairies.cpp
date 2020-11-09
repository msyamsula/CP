#include<bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

int pascal[301][301];

void dfs(vvi mgraph, int u, vi &visited, int &fwdCount){
    visited[u] = 1;
    for(int i=1; i<mgraph[u].size(); i++){
        if (mgraph[u][i] == 0) continue;
        int v = i;
        if (visited[v] == 0){
            fwdCount++;
            dfs(mgraph, v, visited, fwdCount);
        }
    }
}

void solve(int tc){
    int n; cin>>n;
    vi zeros(n+1, 0);
    vvi mgraph(n+1, zeros);
    // for(int i=1; i<=n; i++){
    //     for(int j=1; j<=n; j++){
    //         cout << mgraph[i][j] << ' ';
    //     }
    //     cout << endl;
    // }
    for (int i=1;i<=n;i++){
        for (int j=1; j<=n; j++){
            cin>>mgraph[i][j];
        }
    }

    vi visited(n+1,0);
    int subset = 0;
    int stick = 0;
    for (int u=1; u<=n; u++){
        if (visited[u] == 0){
            int fwd = 0;
            dfs(mgraph, u, visited, fwd);
            stick += ceil(double(fwd)/2);
            cout << u << ' ' << visited[u] << ' ' << stick << endl;
        }
    }

    for (int k=3; k<=stick; k++){
        // cout << stick <<' ' << k << ' ' << pascal[stick][k] << endl;
        subset += pascal[stick][k];
    }
    
    // cout << stick << ' ' << fwd << endl;


    cout << "Case #" << tc << ": " << subset << endl;
}

int main(){
    int tc; cin>>tc;

    pascal[0][0] = 1;
    for(int n=1; n<300; n++){
        pascal[n][0] = 1;
        pascal[n][n] = 1;
        for (int k=1; k<n; k++){
            pascal[n][k] = pascal[n-1][k-1] + pascal[n-1][k];
        }
    }

    // for(int i=0; i<10; i++){
    //     for (int j=0; j<10; j++){
    //         cout << pascal[i][j] << ' ';
    //     }
    //     cout << endl;
    // }

    for(int i=0; i<tc; i++){
        solve(i+1);
    }

    return 0;
}