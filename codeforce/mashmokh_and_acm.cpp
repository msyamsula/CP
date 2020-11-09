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

ll n, k;
ll modulo = 1000000000+7;

void solve(){
    cin>>n>>k;
    vvl dp; dp.assign(n+1, vl(k+1, 0));
    for(ll i=1; i<=n; i++){
        dp[i][1] = 1;
    }

    for(ll j=1; j<k; j++){
        for(ll i=1; i<=n; i++){
            ll nj = j+1;
            for(ll m=1; m*i<=n; m++){
                ll ni = m*i;
                dp[ni][nj] += dp[i][j];
                dp[ni][nj] %= modulo;
            }
        }
    }

    // for(vl a : dp){
    //     for(ll num : a){
    //         cout << num << ' ';
    //     }
    //     cout << endl;
    // }

    ll ans = 0;
    for(ll end=1; end<=n; end++){
        ans += dp[end][k];
        ans %= modulo;
    }

    cout << ans << endl;
}

int main(){
    solve();
    // int tc; cin>>tc;
    // for(int i=0; i<tc; i++){
    //     cout << "Case #" << i+1 << ": ";
    // }

    return 0;
}
