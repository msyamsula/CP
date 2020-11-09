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

void solve(){
    cin>>n;
    ll idx = n;
    ll ans = 0;
    // cout << "b_i: " << b_i << endl;
    while(dp[ans][idx]!=1){
        ans++;
    }

    cout << ans << endl;
}

int main(){
    ll sz = 100001;
    dp.resize(0);
    vl zonk(sz,0); zonk[0]=1;
    vl ones(sz,1);
    dp.push_back(zonk);
    vl row = *dp.rbegin();
    while(row != ones){
        vl new_row(sz,0);
        for(ll i=0; i<(row).size(); i++){
            if (row[i] == 0) continue;
            for(ll j=0; j*j<=sz; j++){
                ll col = i+j*j;
                if (col>=sz) break;
                new_row[col] = 1;
            }
        }
        dp.push_back(new_row);
        row = *dp.rbegin();
    }
    // for(bitset<10001> bs : dp){
    //     cout << bs << endl;
    // }

    // for(vl arr : dp){
    //     for(ll num : arr){
    //         cout << num << ' ';
    //     }
    //     cout << endl;
    // }


    int tc; cin>>tc;
    for(int i=0; i<tc; i++){
        // cout << "Case #" << i+1 << ": ";
        solve();
    }

    return 0;
}
