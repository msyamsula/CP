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
    arr.resize(0);
    cin>>n;
    vvl block;
    vl cur;
    for(ll i=0; i<=n; i++){
        if (i==n){
            block.push_back(cur);
            continue;
        }
        ll temp; cin>>temp;
        arr.push_back(temp);
        if (i==0) cur.push_back(temp);
        else if (*cur.rbegin()*temp < 0){
            block.push_back(cur);
            cur.resize(0);
            cur.push_back(temp);
        } else if (*cur.rbegin()*temp > 0){
            cur.push_back(temp);
        }
    }

    // cout << "block: " << endl;
    // for(vl a : block){
    //     for (ll num : a){
    //         cout << num << ' ';
    //     }
    //     cout << endl;
    // }

    ll ans = 0;
    for(ll i=0; i<block.size(); i++){
        ll maxnum = -MAXLL;
        for(ll j=0; j<block[i].size(); j++){
            maxnum = max(maxnum, block[i][j]);
        }
        ans += maxnum;
    }

    cout << ans << endl;


}

int main(){
    int tc; cin>>tc;
    for(int i=0; i<tc; i++){
        // cout << "Case #" << i+1 << ": ";
        solve();
    }

    return 0;
}
