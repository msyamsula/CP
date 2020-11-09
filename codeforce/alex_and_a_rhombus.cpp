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
ll dp;

void solve(){
    cin>>n;
    // dp.resize(0); dp.assign(n+1, 0);
    dp = 1;
    // dp[0]=1;
    ll add=0;
    for(ll i=0; i<n; i++){
        // dp[i+1] = dp[i]+add;
        ll copy = dp;
        dp = copy+add;
        add+=4;
        // cout << dp << ' ';
    }
    // cout << endl;

    // cout << "dp: ";
    // for(ll num : dp){
    //     cout << num << ' ';
    // }
    // cout << endl;

    cout << dp << endl;
}

int main(){
    solve();

    return 0;
}
