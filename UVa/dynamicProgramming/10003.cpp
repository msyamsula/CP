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

ll len;
vl arr;
vl ps;
vvl dp;

void solve(){
    arr.resize(0); ps.resize(0); dp.resize(0);
    ll n; cin>>n;
    ll pl = 0;
    for(ll i=0; i<n; i++){
        ll temp; cin>>temp;
        arr.push_back(temp-pl);
        pl = temp;
    }
    arr.push_back(len-pl);
    n = arr.size();
    ps.assign(n+1, 0);
    for(ll i=0; i<n; i++){
        ps[i+1] = ps[i]+arr[i];
    }
    dp.assign(n, vl(n, 0));
    for(ll d=1; d<n; d++){
        for(ll i=0; i<n; i++){
            ll j=i+d;
            if (j>=n) continue;
            dp[i][j] = MAXLL;
            for(ll m=i; m<j; m++){
                dp[i][j]= min(dp[i][j], dp[i][m]+dp[m+1][j]+ps[j+1]-ps[i]);
            }
            
        }
        // cout << d << endl;
        // for(vl temp : dp){
        //     for(ll num : temp){
        //         cout << num << ' ';
        //     }
        //     cout << endl;
        // }
    }

    cout << "The minimum cutting is " << dp[0][n-1] << '.' << endl;
}

int main(){
    // int tc; cin>>tc;
    while(cin>>len){
        if (len==0) break;
        // cout << "Case #" << i+1 << ": ";
        solve();
    }

    return 0;
}
