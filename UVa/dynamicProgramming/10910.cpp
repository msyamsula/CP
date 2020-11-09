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
    dp.resize(0);
    ll n,t,p; cin>>n>>t>>p;
    ll addlen = t-p*n;
    // cout << addlen << ' ' << p << endl;    
    dp.assign(n+1, vl(t+1, -1));
    dp[0][0]=1;
    for(ll i=0; i<=n; i++){
        for(ll j=0; j<=t; j++){
            if (i+1 > n) continue;
            if (dp[i][j]==-1) continue;
            // cout << i << ' ' << j << endl;
            for(ll ii=0; ii<=addlen; ii++){
                ll nj = j+p+ii;
                if (nj>t) break;
                // dp[i+1][nj]=0;
                if (dp[i+1][nj]==-1) dp[i+1][nj]=dp[i][j];
                else dp[i+1][nj]+=dp[i][j];
            }
        }
    }

    // for(vl temp : dp){
    //     for(ll num : temp){
    //         cout << num << ' ';
    //     }
    //     cout << endl;
    // }

    cout << ((dp[n][t]==-1)?0:dp[n][t]) << endl;
    
}

int main(){
    int tc; cin>>tc;
    for(int i=0; i<tc; i++){
        // cout << "Case #" << i+1 << ": ";
        solve();
    }

    return 0;
}
