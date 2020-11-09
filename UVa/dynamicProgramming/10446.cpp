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
ll n,back;
map<vl, ll> dp;

ll trib(ll n, ll back) {
    // cout << n << ' ' << back << endl;
    if (dp.find({n,back}) != dp.end()) return dp[{n,back}];

    if (n<=1) return dp[{n,back}] = 1;
    ll cnt = 0;
    for(ll i=1; i<=back; i++){
        cnt += trib(n-i, back);
    }
    // cout << "cnt: " << cnt << endl;
    return dp[{n,back}] = 1+cnt;
}

void solve(){
    if (dp.find({n,back}) != dp.end()){
        cout << (ll)dp[{n,back}] << endl;
        return;
    }
    cout << (ll)trib(n,back) << endl;

    // for(pair<vl, ll> p : dp){
    //     cout << p.first[0] << ' ' << p.first[1] << endl;
    //     cout << p.second << endl;
    // }
}

int main(){
    // ll tc=1;
    // while(cin>>n>>back){
    //     if (n>60) break;
    //     cout << "Case " << tc << ": ";
    //     solve();
    //     tc++;
    // }
    vvl tes;
    ll sz = 50000;
    tes.resize(sz);
    vl temp(sz,0);
    // for(ll j=0; j<sz; j++){
    //     // cout << "j: " << j << endl;
    //     temp.push_back(j);
    // }
    for(ll i=0; i<sz; i++){
        tes[i] = temp;
    }
    // int tc; cin>>tc;
    // for(int i=0; i<tc; i++){
    //     solve();
    // }

    return 0;
}
