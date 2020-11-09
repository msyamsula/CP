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

vvl dp;

void solve(){

}

int main(){
    ll n = 2000000; dp.assign(2,vl(n,0));
    dp[0][0] = dp[1][0] = 1;
    for(ll i=0; i<n; i++){
        if (i+1<n) dp[0][i+1] += dp[0][i]+dp[1][i]; dp[1][i+1] += dp[0][i]+dp[1][i];
        if (i+2<n) dp[0][i+2] -= dp[0][i];
        if (i+3<n) dp[1][i+3] -= dp[1][i];
    }

    // for(vl temp : dp){
    //     for(ll num : temp){
    //         cout << num << ' ';
    //     }
    //     cout << endl;
    // }
    
    // int tc; cin>>tc;
    // for(int i=0; i<tc; i++){
    //     cout << "Case #" << i+1 << ": ";
    //     solve();
    // }

    return 0;
}
