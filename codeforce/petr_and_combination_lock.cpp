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
vl rotations;
vl dp;

void solve(){
    cin>>n;
    rotations.resize(0);
    for(ll i=0; i<n; i++){
        ll temp; cin>>temp;
        rotations.push_back(temp);
    }
    dp.resize(0);
    dp.assign(360, 0);
    dp[0] = 1;
    for(ll i=0; i<n; i++){
        // for(ll num : dp){
        //     cout << num << ' ';
        // }
        // cout << endl;
        vl copy(360, 0);
        for(ll j=0; j<360; j++){
            if (dp[j] == 0) continue;
            ll nj_c = j+rotations[i], nj_cc = j-rotations[i];
            nj_c %= 360;
            if (nj_cc < 0) nj_cc += 360;
            nj_cc %= 360;
            if (nj_c < 360) copy[nj_c] = 1;
            if (nj_cc < 360) copy[nj_cc] = 1;
        }
        dp = copy;
    }
    // for(ll num : dp){
    //     cout << num << ' ';
    // }
    // cout << endl;

    cout << ((dp[0] == 1) ? "YES": "NO") << endl;


}

int main(){
    solve();
    // int tc; cin>>tc;
    // for(int i=0; i<tc; i++){
    //     cout << "Case #" << i+1 << ": ";
    // }

    return 0;
}
