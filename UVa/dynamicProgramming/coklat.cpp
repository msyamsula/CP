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
vl ps;

void solve(){
    ll n; cin>>n;
    dp.resize(0); dp.assign(n, vl(n, 0));
    ps.resize(0); ps.assign(n+1,0);
    for(ll i=0; i<n; i++){
        // cin>>dp[i][i];
        ll temp; cin>>temp;
        ps[i+1] = ps[i]+temp;
    }


    for(ll sz=1; sz<n; sz++){
        for(ll i=0; i<n; i++){
            if (i+sz >= n) continue;
            // cout << i << endl;
            dp[i][i+sz] = MAXLL;
            for(ll m=i; m<i+sz; m++){
                dp[i][i+sz] = min(dp[i][i+sz], dp[i][m]+dp[m+1][i+sz]+ps[i+sz+1]-ps[i]);
            }
        }
    }

    for( vl temp: dp){
        for(ll num : temp){
            cout << num << ' ';
        }
        cout << endl;
    }

    cout << dp[0][n-1] << endl;
}

int main(){
    int tc; cin>>tc;
    for(int i=0; i<tc; i++){
        cout << "Case #" << i+1 << ": ";
        cout << endl;
        solve();
    }

    return 0;
}
