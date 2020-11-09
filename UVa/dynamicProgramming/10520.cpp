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
ll n;

ll calculate(ll i, ll j){
    // cout << "dp: " << endl;
    // for(vl arr : dp){
    //     for(ll num : arr){
    //         cout << num << ' ';
    //     }
    //     cout << endl;
    // }
    // cout << "cal: " << i << ' ' << j << endl;
    // cout << "dp: " << dp[i][j] << endl;
    // cout << "memo: " << (dp[i][j] != -MAXLL) << endl;


    if (dp[i][j] != -MAXLL) return dp[i][j];

    if (i<j){
        ll maxnum = 0;
        for(ll k=i; k<j; k++){
            // cout << k << endl;
            ll left = calculate(i,k), right = calculate(k+1,j);
            // cout << i <<  ' ' << j << ' ' << k << endl;
            // cout  << left << ' ' << right << endl;
            maxnum = max(maxnum, left+right);
        }
        // cout << "maxnum: " << maxnum << endl;
        dp[i][j] = maxnum;
        return dp[i][j];
    }

    // cout << i << ' ' << j << endl;
    ll left,right;
    if (i<n){
        left = 0;
        for(ll k=i+1; k<=n; k++){
            left = max(left, calculate(k,1)+calculate(k,j));
        }
    } else if (i==n){
        left = 0;
    }
    // cout << "left: " << left << endl;

    if (j==0){
        right = 0;
    } else if (j>0){
        right = 0;
        for(ll k=1; k<j; k++){
            right = max(right, calculate(i,k)+calculate(n,k));
        }
    }
    // cout << "right: " << right << endl;

    // cout << left + right << endl;

    dp[i][j] = left+right;
    return dp[i][j];
}

void solve(){
    // cin>>n;
    dp.resize(0); dp.assign(n+1, vl(n+1, -MAXLL));
    cin>>dp[n][1];
    cout << calculate(1,n) << endl;
}

int main(){
    while(cin>>n){
        solve();
    }

    return 0;
}
