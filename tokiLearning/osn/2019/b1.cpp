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

ll N, M, S;
map<vl, ll> obat;

void solve(){
    // obat.resize(0);
    obat.clear();
    ll n = N, m=M;
    for(ll i=0; i<m; i++){
        ll a,b,p; cin>>a>>b>>p;
        obat[{a,b}] = p;
    }

    for(ll i=1; i<=n; i++){
        if (obat.find({i,i}) == obat.end()){
            obat[{i,i}] = S;
        } else {
            obat[{i,i}] = min(obat[{i,i}], S);
        }
    }

    vl dp; dp.assign(n+1, 0);
    for(ll i=0; i<=n; i++){
        dp[i] = i*S;
    }
    for(ll i=0; i<5; i++){
        auto it = obat.lower_bound({i,i});
        if (it == obat.end()) continue;
        while(it->first[0] - i < 2){
            ll end = it->first[1];
            if (end>i){
                dp[end] = min(dp[end], dp[i]+it->second);
            }
            it++;
            if (it == obat.end()) break;
        }
    }

    // for(ll num : dp){
    //     cout << num << ' ';
    // }
    // cout << endl;

    cout << dp[n] << endl;
}

int main(){
    while(cin>>N>>M>>S){
        solve();
    }

    return 0;
}
