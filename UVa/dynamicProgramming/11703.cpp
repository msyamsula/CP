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

vl dp;

void solve(){

}

int main(){
    ll n = 1000000;
    dp.assign(n+1, 0);
    dp[0] = 1;
    for(ll i=1; i<n+1; i++){
        ll i1 = floor(double(i) - pow(i,0.5));
        ll i2 = floor(log(i));
        ll i3 = floor(double(i)*pow(sin(i),2));
        dp[i] += dp[i1]; dp[i]%=n;
        dp[i] += dp[i2]; dp[i]%=n;
        dp[i] += dp[i3]; dp[i]%=n;
    }
    ll idx;
    while(cin>>idx){
        if (idx==-1) break;
        cout << dp[idx] << endl;
    }
    // int tc; cin>>tc;
    // for(int i=0; i<tc; i++){
    //     cout << "Case #" << i+1 << ": ";
    //     solve();
    // }
    // cout << log(2.71) << endl;
    return 0;
}
