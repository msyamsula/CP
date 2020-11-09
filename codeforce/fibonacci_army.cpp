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
vl dp;

void solve(){
    cin>>n;
    if (n<2){
        cout << 1 << endl;
        return;
    }
    dp.resize(0); dp.assign(3, 0);
    dp[0]=dp[1]=1;
    for(ll i=2; i<=n; i++){
        dp[2] = dp[0] + dp[1];
        vl copy = dp;
        copy[0]=dp[1];
        copy[1]=dp[2];
        dp = copy;
    }

    // for(ll num : dp){
    //     cout << num << ' ';
    // }
    // cout << endl;

    cout << dp[2] << endl;

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
