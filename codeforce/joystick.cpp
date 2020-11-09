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

ll a,b;
vl dp;

void solve(){
    cin>>a>>b;
    dp.assign(2, 0);
    dp[0]=a; dp[1]=b;
    ll ans = 0;
    while(dp[0] > 0 && dp[1] > 0){
        vl one(2,0);
        // p1 charge
        one[0] = dp[0] + 1;
        one[1] = dp[1] - 2;

        vl two(2,0);
        // p2 charge
        two[0] = dp[0] - 2;
        two[1] = dp[1] + 1;

        // choose best option
        if ( min(one[0], one[1]) >= min(two[0], two[1]) ){
            dp = one;
        } else {
            dp = two;
        }
        // dp = copy
        // for (ll num : dp){
        //     cout << num << ' ';
        // }
        // cout << endl;
        if (min(dp[0], dp[1]) < 0) break;
        ans++;
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
