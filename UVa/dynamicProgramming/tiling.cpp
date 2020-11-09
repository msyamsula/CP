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
    ll n; cin>>n;
    dp.resize(0); dp.assign(n+1,0);
    dp[0]=1;
    for(ll i=0; i<=n; i++){
        if (i+1<=n) dp[i+1]+=dp[i];
        if (i+1<=n) dp[i+2]+=dp[i];
        if (i+1<=n) dp[i+3]+=dp[i];
    }

    for(ll num : dp){
        cout << num << ' ';
    }
    cout << endl;
    // int tc; cin>>tc;
    // for(int i=0; i<tc; i++){
    //     cout << "Case #" << i+1 << ": ";
    //     solve();
    // }

    return 0;
}
