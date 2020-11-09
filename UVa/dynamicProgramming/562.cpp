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
void showV(vl temp){
    for(ll t : temp){
        cout << t << ' ';
    }
    cout << endl;
}

void showVV(vvl temp){
    for (vl t : temp){
        for(ll t1 : t){
            cout << t1 << ' ';
        }
        cout << endl;
    }
    cout << endl;
}

ll m;
vl coin;

void solve(){
    cin>>m;
    coin.resize(0);
    ll sum = 0;
    for(ll i=0; i<m; i++){
        ll temp; cin>>temp;
        coin.push_back(temp);
        sum+=temp;
    }

    // cout << "sum: " << sum << endl;

    vl dp(sum+1, 0);
    dp[0] = 1;

    for(ll i=0; i<m; i++){
        vl new_dp(sum+1, 0);
        for(ll j=0; j<sum+1; j++){
            if (dp[j]){
                new_dp[j] = 1;
                ll nj = j+coin[i];
                if (nj > sum) continue;
                new_dp[nj] = 1;
            }
        }
        dp = new_dp;
    }

    ll ans = MAXLL;
    for(ll i=0; i<sum+1; i++){
        if (dp[i]){
            ll a = i;
            ll b = sum-i;
            ll dif = abs(a-b);
            ans = min(dif, ans);
        }
    }

    // showV(dp);

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
