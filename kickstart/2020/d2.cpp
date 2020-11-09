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
vl arr;

void solve(){
    cin>>n;
    arr.resize(0);
    for(ll i=0; i<n; i++){
        ll temp; cin>>temp;
        arr.push_back(temp);
    }

    vvl dp; dp.assign(4, vl(n, MAXLL));
    for(ll i=0; i<4; i++){
        dp[i][0] = 0;
    }

    for(ll j=0; j<n-1; j++){
        for(ll i=0; i<4; i++){
            // up condition
            if (arr[j+1] > arr[j]){
                if (i==3){ // has no up possibilty
                    for (ll ii=0; ii<4; ii++){
                        dp[ii][j+1] = min(dp[ii][j+1], dp[i][j]+1);
                    }
                } else { // has up possibility
                    for (ll step=1; step<4; step++){
                        if (i+step >= 4) break;
                        dp[i+step][j+1] = min(dp[i+step][j+1], dp[i][j]);
                    }
                }
            }
            // down condition
            if (arr[j+1] < arr[j]){
                if (i == 0){ // has no down possibility
                    for(ll ii=1; ii<4; ii++){
                        dp[ii][j+1] = min(dp[ii][j+1], dp[i][j]+1);
                    }
                } else { // has down possibilty
                    for(ll step = 1; step<4; step++){
                        if (i-step < 0) break;
                        dp[i-step][j+1] = min(dp[i-step][j+1], dp[i][j]);
                    }
                }
                
            }
            // same condition
            if (arr[j+1] == arr[j]){
                dp[i][j+1] = min(dp[i][j+1], dp[i][j]);
            }
        }
    }

    // for (vl arr : dp){
    //     for (ll num : arr){
    //         cout << num << ' ';
    //     }
    //     cout << endl;
    // }

    ll ans = MAXLL;
    for(ll i=0; i<4; i++){
        ans = min(ans, dp[i][n-1]);
    }

    cout << ans << endl;
}

int main(){
    int tc; cin>>tc;
    for(int i=0; i<tc; i++){
        cout << "Case #" << i+1 << ": ";
        solve();
    }

    return 0;
}
