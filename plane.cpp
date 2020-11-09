#include<bits/stdc++.h>
using namespace std;


void solve(){
    int d; cin>>d;
    // cout << d << endl;
    int n = d/100;
    int wind[10][n];
    for(int i=0; i<10; i++){
        for(int j=0; j<n; j++){
            cin>>wind[i][j];
        }
    }

    // for(int i=0; i<10; i++){
    //     for(int j=0; j<n; j++){
    //         cout<<wind[i][j]<<' ';
    //     }
    //     cout << endl;
    // }

    int dp[10][n+1];
    for(int i=0; i<10; i++){
        for(int j=0; j<n+1; j++){
            dp[i][j] = 1<<30;
        }
    }

    dp[9][0] = 0;


    for(int i=0; i<n; i++){
        for(int h=9; h>=0; h--){
            if (dp[h][i] == 1<<30) break;
            int lh = h+1;
            int hh = h-1;
            dp[h][i+1] = min(dp[h][i+1], 30 - wind[h][i] + dp[h][i]);
            
            if (hh >= 0) dp[hh][i+1] = min(dp[hh][i+1], 60 - wind[h][i] + dp[h][i]);
            if (lh < 10) dp[lh][i+1] = min(dp[lh][i+1], 20 - wind[h][i] + dp[h][i]);
        }
    }

    // for(int i=0; i<10; i++){
    //     for(int j=0; j<n+1; j++){
    //         cout<<dp[i][j]<<' ';
    //     }
    //     cout << endl;
    // }
    cout << dp[9][n] << endl << endl;
}

int main(){
    int tc; cin>>tc;
    for(int i=0; i<tc; i++){
        // if (i != 0) cout << endl;
        solve();
    }

    return 0;
}