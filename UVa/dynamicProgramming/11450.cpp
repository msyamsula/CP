#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<long> vl;
typedef vector<vl> vvl;
#define INF 1<<30

void solve(){
    int m,c; cin>>m>>c;
    vvi price(c);
    for(int i=0; i<c; i++){
        int n; cin>>n;
        price[i].resize(n);
        for(int j=0; j<n; j++){
            cin>>price[i][j];
        }
    }

    vvi dp(c+1, vi(m+1,0));
    dp[0][0] = 1;

    for(int i=1; i<=c; i++){
        for(int j=0; j<=m; j++){
            dp[i][j] = 0;
            int ip = i-1;
            for(int k=0; k<price[ip].size(); k++){
                if (j>=price[ip][k]) dp[i][j] |= dp[i-1][j-price[ip][k]];
            }
            // cout << dp[i][j] << ' ';
        }
        // cout << endl;
    }

    int ans = -1;
    for(int money=m; money>=0; money--){
        if (dp[c][money] == 1){
            ans = money;
            break;
        }
    }

    if (ans == -1){
        cout << "no solution" << endl;
        return;
    }

    cout << ans << endl;

}

int main(){
    int t; cin>>t;
    for(int i=0; i<t; i++){
        solve();
    }

    return 0;
}