#include<bits/stdc++.h>
using namespace std;
typedef vector<long> vi;
typedef vector<vi> vvi;
typedef map<vi, long> mbsi;
#define MAX pow(2,60)
vvi graph;
vi beauty;
vvi dp;
vi illum;

void solve(){
    graph.resize(0);
    beauty.resize(0);
    dp.resize(0);
    illum.resize(0);

    int n; cin>>n;
    graph.assign(n, vi(0));
    beauty.assign(n,0);
    dp.assign(2, vi(n+1,-MAX));
    illum.assign(n,0);

    for(int i=0; i<n; i++){
        cin>>beauty[i];
    }

    for(int i=0; i<n-1; i++){
        int u,v; cin>>u>>v;
        u--; v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    dp[0][0] = 0;
    for(int i=1; i<=n; i++){
        int u = i-1;
        long value = (illum[u] == 0) ? beauty[u] : 0;
        for(long v:graph[u]){
            if (illum[v] == 0) value += beauty[v];
        }
        dp[0][i] = max(dp[0][i-1], dp[1][i-1]) + value;
        dp[1][i] = max(dp[0][i-1], dp[1][i-1]);

        if (dp[0][i] > dp[1][i]){
            illum[u] = 1;
            for(long v : graph[u]){
                illum[v] = 1;
            }
        }
        // cout << "tes" << endl;
    }

    // for(vi temp : dp){
    //     for (long num : temp){
    //         cout << num << ' ';
    //     }
    //     cout << endl;
    // }

    cout << max(dp[0][n], dp[1][n]) << endl;
}

int main(){
    long tc; cin>>tc;
    for(long i=0; i<tc; i++){
        cout << "Case #" << i+1 << ": ";
        solve();
    }

    return 0;
}