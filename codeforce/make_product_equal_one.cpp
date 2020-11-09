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

ll n;
vl coins;
vvl dp;

void solve(){
    cin>>n;
    coins.resize(0);
    for(ll i=0; i<n; i++){
        ll temp; cin>>temp;
        coins.push_back(temp);
    }

    dp.resize(0); dp.assign(2, vl(n+1, MAXLL));
    dp[0][0] = 0;
    for(ll j=0; j<n; j++){
        for(ll i=0; i<2; i++){
            if (dp[i][j] == MAXLL) continue;
            ll pone = abs(1-coins[j]);
            ll none = abs(-1-coins[j]);
            // cout << j << ' ' << pone << ' ' << none << endl;
            if (i==0){
                dp[0][j+1] = min(dp[0][j+1], dp[0][j]+pone);
                dp[1][j+1] = min(dp[1][j+1], dp[0][j]+none);
            }

            if (i==1){
                dp[0][j+1] = min(dp[0][j+1], dp[1][j]+none);
                dp[1][j+1] = min(dp[1][j+1], dp[1][j]+pone);
            }
        }
    }

    // for(vl arr: dp){
    //     for(ll num : arr){
    //         cout << num << ' ';
    //     }
    //     cout << endl;
    // }

    cout << dp[0][n] << endl;
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
