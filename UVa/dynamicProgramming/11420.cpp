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

ll n, s;
vvl dp;

void solve(){
    // cin>>n>>s;
    dp.resize(0); dp.assign(n+1, vl(2*(s+1), 0));
    dp[0][0] = 1;
    for(ll i=0; i<n; i++){
        for(ll j=0; j<2*(s+1); j++){
            if (dp[i][j] == 0) continue;
            ll status = j/(s+1);
            if (status == 0){
                if (j<s) dp[i+1][j+1] += dp[i][j];
                dp[i+1][j+(s+1)] += dp[i][j];
            } else if (status == 1){
                dp[i+1][j-(s+1)] += dp[i][j];
                // if (j < 2*(s+1)) 
                dp[i+1][j] += dp[i][j];
            }
        }
    }

    // for(vl arr : dp){
    //     for(ll num : arr){
    //         cout << num << ' ';
    //     }
    //     cout << endl;
    // }
    // cout << endl;

    ll sum = 0;
    for(ll i=0; i<dp.size(); i++){
        sum += dp[i][s];
    }

    cout << sum << endl;
}

int main(){
    while(cin>>n>>s){
        if (n<0 && s<0) break;
        solve();
    }

    return 0;
}
