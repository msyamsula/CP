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

ll h,tc;
vl height;

void solve(ll t){
    vl r_h;
    ll n=height.size();
    for(ll i=n-1; i>=0; i--){
        r_h.push_back(height[i]);
    }

    vl dp; dp.assign(n, 1);
    ll ans = 1;
    for(ll i=1; i<n; i++){
        ll max_num = 0;
        for(ll j=0; j<i; j++){
            if (r_h[j]<=r_h[i]){
                max_num = max(max_num, dp[j]);
            }
        }
        dp[i] += max_num;
        ans = max(ans, dp[i]);
    }

    // for(ll num : dp){
    //     cout << num << ' ';
    // }    
    // cout << endl;
    if (t!=1) cout << endl;
    cout << "Test #" << t << ':' << endl;
    cout << "  maximum possible interceptions: "<< ans << endl;
    // cout << ans << endl;
}

int main(){
    tc = 1;
    while(cin>>h){
        if(h==-1){
            if(height.size() > 0){
                solve(tc);
                height.resize(0);
                tc++;
            } else break;
        } else {
            height.push_back(h);
        }
    }

    return 0;
}
