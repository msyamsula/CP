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
// vl dp;

void solve(){
    cin>>n;
    // dp.resize(0); dp.assign(n+1, 0);
    // dp[0] = 1;
    // for(ll i=0; i<n; i++){
    //     if (dp[i] == 0) continue;
    //     if (i+2 <= n) dp[i+2] = dp[i]*2;
    // }

    // cout << "dp: ";
    // for(ll num : dp){
    //     cout << num << ' ';
    // }
    // cout << endl;

    if (n%2 == 1){
        cout << 0 << endl;
        return;
    }

    cout << (1<<(n/2)) << endl;
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
