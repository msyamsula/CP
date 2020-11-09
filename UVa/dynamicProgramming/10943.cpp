#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<long> vl;
typedef vector<vl> vvl;
#define INF 1<<30

void solve(int n, int k){
    vvl dp(k+1, vl(n+1, 0));
    dp[0][0] = 1;

    for(int i=1; i<=k; i++){
        for(int j=0; j<=n; j++){
            if (j==0){
                dp[i][j] = 1;
                continue;
            }

            dp[i][j] = 0;
            for(int coin=0; coin<=n; coin++){
                if (j-coin < 0) continue;
                dp[i][j] += dp[i-1][j-coin];
            }
            dp[i][j] %= 1000000;
            // dp[i][j] = (dp[i][j] <= 1000000) ? dp[i][j] : dp[i][j]-1000000;
            // cout << dp[i][j] << ' ';
        }
        // cout << endl;
    }

    cout << dp[k][n] << endl;
}

int main(){
    int n,k;
    while(true){
        cin>>n>>k;
        if (n==0 && k==0) break;
        solve(n,k);
    }

    return 0;
}