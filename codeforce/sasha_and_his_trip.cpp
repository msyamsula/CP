#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<long long> vl;
typedef vector<vl> vvl;
typedef vector<string> vs;
typedef vector<vs> vvs;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;
typedef long long ll;
#define MAXLL (1ll<<60)
#define MAXI (1<<30)

ll n,v;
vvl dp;

void solve(){
    cin>>n>>v;
    dp.resize(0);
    dp.assign(v, vl(n+1, MAXLL));
    dp[0][0] = 0;
    for(ll i=0; i<v; i++){
        dp[i][0] = i;
    }
    for(ll j=0; j<n; j++){
        for(ll i=0; i<v; i++){
            if (dp[i][j] == MAXLL) continue;
            ll cfuel = i;
            ll price = (v-cfuel)*(j+1);
            for(ll len = 1; len<=v; len++){
                ll nj = j+len;
                if (nj>n) continue;
                dp[v-len][nj] = min(dp[v-len][nj], dp[i][j]+price);
            }

            for(ll len=i; len>0; len--){
                if (j+len > n) continue;
                dp[i-len][j+len] = min(dp[i-len][j+len], dp[i][j]);
            }
        }
    }

    // for(vl arr : dp){
    //     for(ll num : arr){
    //         cout << num << ' ';
    //     }
    //     cout << endl;
    // }
    
    ll ans = MAXLL;
    for(ll i=0; i<v; i++){
        // cout << dp[i][n-1] << endl;
        ans = min(ans, dp[i][n-1]);
    }

    cout << ans << endl;

}

int main(){
    solve();
    // int tc; cin>>tc;
    // for(int i=0; i<tc; i++){
    //     cout << "Case #" << i+1 << ": ";
    //     solve();
    // }

    return 0;
}
