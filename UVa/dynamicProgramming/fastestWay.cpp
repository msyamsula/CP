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
vl arr;

void solve(){

}

int main(){
    arr.resize(0);
    ll n; cin>>n;
    for(ll i=0; i<n; i++){
        ll ntemp; cin>>ntemp;
        arr.push_back(ntemp);
    }

    dp.resize(0); dp.assign(n, MAXLL);
    dp[0]=0;
    for(ll i=0; i<n; i++){
        if (i+1<n) dp[i+1] = min(dp[i+1],dp[i]+1);
        if (i+arr[i]<n) dp[i+arr[i]] = min(dp[i+arr[i]], dp[i]+1);
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
