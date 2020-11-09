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

ll t,h,f;
vvl oak;

void solve(){
    cout << "tes" << endl;
    // cin>>t>>h>>f;
    // oak.resize(0); oak.resize(t);
    // vector<map<ll, ll>> cnt_oak;
    // cnt_oak.resize(t);
    // for(ll i=0; i<t; i++){
    //     ll c; cin>>c;
    //     for(ll j=0; j<c; j++){
    //         ll val; cin>>val;
    //         oak[i].push_back(val);
    //         cnt_oak[i][val]++;
    //     }
    // }

    // vvl dp; dp.assign(h+1, vl(t, 0));
    // ll ans = 0;
    // for(ll i=0; i<h; i++){
    //     for(ll j=0; j<t; j++){
    //         ll cur_oak = dp[i][j];
    //         for(ll tree=0; tree<t; tree++){
    //             if (tree == j){
    //                 vl::iterator next_h = lower_bound(oak[tree].begin(), oak[tree].end(), i+1);
    //                 if ( next_h == oak[tree].end() ) continue;
    //                 dp[*next_h][tree] = max(dp[*next_h][tree], dp[i][j]+cnt_oak[tree][*next_h]);
    //                 ans = max(ans, dp[*next_h][tree]);
    //                 continue;
    //             }

    //             vl::iterator next_h = lower_bound(oak[tree].begin(), oak[tree].end(), i+f);
    //             if ( next_h == oak[tree].end() ) continue;
    //             dp[*next_h][tree] = max(dp[*next_h][tree], dp[i][j]+cnt_oak[tree][*next_h]);
    //             ans = max(ans, dp[*next_h][tree]);
    //         }
    //     }
    // }

    // for(vl temp:dp){
    //     for(ll num:temp){
    //         cout << num << ' ';
    //     }
    //     cout << endl;
    // }

    // cout << endl;
    cin>>t>>h>>f;
    vvl trees; trees.assign(t, vl(h+1, 0));
    for(ll i=0; i<t; i++){
        ll temp; cin>>temp;
        for(ll j=0; j<temp; j++){
            ll height; cin>>height;
            trees[i][height]++;
        }
    }

    vl dp; dp.assign(h+1, 0);
    for(ll i=0; i<h; i++){
        for(ll j=0; j<t; j++){
            dp[i+1] = max(dp[i]+trees[j][i], dp[i+1]);
            if (i-f>=0) dp[i+1] = max(dp[i-f]+trees[j][i], dp[i+1]);
        }
    }

    for (ll num : dp){
        cout << num << ' ';
    }
    cout << endl;
}

int main(){
    int tc; cin>>tc;
    for(int i=0; i<tc; i++){
        // cout << "Case #" << i+1 << ": ";
        solve();
    }

    return 0;
}
