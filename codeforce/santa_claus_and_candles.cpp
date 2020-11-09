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
vvl dp;
vl coins;

void backtrack(ll r, ll c){
    // ll coin = 0;
    if (c == 0) return;
    ll coin = r;
    if (dp[r-1][c-coin]+1 == dp[r][c]){
        coins.push_back(coin);
        return backtrack(r-1,c-coin);
    }
    return backtrack(r-1,c);
}

void solve(){
    cin>>n;
    dp.resize(0); dp.assign(n+1, vl(n+1, -MAXLL));
    dp[0][0] = 0;
    for(ll i=0; i<n; i++){
        for(ll j=0; j<=n; j++){
            if (dp[i][j] == -MAXLL) continue;
            ll coin = i+1;
            // pass
            dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
            // take
            ll nj = j+coin;
            if (nj>n) continue;
            dp[i+1][nj] = max(dp[i+1][nj], dp[i][j]+1);
        }
    }

    // cout << "dp: " << endl;
    // for(vl arr : dp){
    //     for(ll num : arr){
    //         cout << num << ' ';
    //     }
    //     cout << endl;
    // }

    cout << dp[n][n] << endl;
    coins.resize(0);
    // coins.clear();
    backtrack(n,n); 
    sort(coins.begin(),coins.end()); 
    ll sum = 0;
    for(ll i=0; i<coins.size(); i++){
        if (i!=0) cout << ' ';
        cout << coins[i];
        sum += coins[i];
    }
    // for(ll num : coins){
    //     cout << num << ' ';
    //     sum+=num;
    // }
    cout << endl;

    // cout << "sum: " << sum << endl;
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
