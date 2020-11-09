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

ll n,d;
vl dp;

void solve(){
    cin>>n>>d;
    dp.resize(0); dp.assign(n, -1);
    dp[0]= 0;
    string path; cin>>path;
    for(ll i=0; i<n-1; i++){
        if (dp[i] == -1 || path[i] == '0') continue;
        for(ll jump=1; jump<=d; jump++){
            ll ni = i+jump;
            if (ni>=n) break;
            if (path[ni] == '0') continue;
            
            if (dp[ni] == -1) dp[ni] = dp[i]+1;
            else dp[ni] = min(dp[ni], dp[i]+1);
        }
    }

    // cout << "dp: ";
    // for (ll num : dp){
    //     cout << num << ' ';
    // }
    // cout << endl;

    cout << dp[n-1] << endl;

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
