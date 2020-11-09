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

vl arr;
vvl dp;

void solve(){
    arr.resize(0); dp.resize(0);
    ll n,k; cin>>n>>k;
    dp.assign(n, vl(k, 0));
    for(ll i=0; i<n; i++){
        ll temp; cin>>temp;
        arr.push_back(temp);
    }

    ll j = arr[0]%k; j = (j<0) ? j+k : j;
    dp[0][j] = 1;
    for(ll i=0; i<n-1; i++){
        for(j=0; j<k; j++){
            if (!dp[i][j]) continue;
            ll s1 = j+arr[i+1], s2 = j-arr[i+1]; s1 %= k; s2 %=k;
            s1 = (s1<0) ? s1+k : s1;
            s2 = (s2<0) ? s2+k : s2;
            dp[i+1][s1] = 1; dp[i+1][s2] = 1;
        }
    }

    if (dp[n-1][0]) cout << "Divisible" << endl;
    else cout << "Not divisible" << endl;
}

int main(){
    int tc; cin>>tc;
    for(int i=0; i<tc; i++){
        // cout << "Case #" << i+1 << ": ";
        solve();
    }
    // cout << (-2)%15 << endl;
    return 0;
}
