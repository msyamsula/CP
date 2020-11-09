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

ll m,n,t;
vl dp;
stack<ll> eatingat;


void backtrack(ll num){
    if (dp[num]==-1){
        backtrack(num-1);
    } else if (dp[num-m]+1==dp[num]){
        eatingat.push(num-m);
        backtrack(num-m);
    } else if (dp[num-n]+1==dp[num]){
        eatingat.push(num-n);
        backtrack(num-n);
    }
}

void solve(){
    dp.assign(t+1, -1);
    dp[0]=0;
    for(ll i=0; i<=t; i++){
        if (dp[i]==-1) continue;
        if (i+m<=t) dp[i+m]= max(dp[i+m], dp[i]+1);
        if (i+n<=t) dp[i+n] = max(dp[i+n], dp[i]+1);
    }

    // ll i =0;
    // for(ll num : dp){
    //     cout << num << ' ';
    //     i++;
    // }
    // cout << endl;

    // backtrack(t);
    // cout << eatingat.size() << endl;
    // while(!eatingat.empty()){
    //     cout << eatingat.top() << ' ';
    //     eatingat.pop();
    // }
    // cout << endl;
    ll drink=0;
    ll idx;
    for(ll i=dp.size()-1; i>=0; i--){
        // cout << i << endl;
        if (dp[i]!=-1){
            // cout << t << ' ' << i << endl;
            idx=i;
            drink = t-i;
            break;
        }
    }
    cout << dp[idx];
    if (drink>0) cout << ' ' << drink;
    cout << endl;
}

int main(){
    // int tc; cin>>tc;
    while(cin>>m>>n>>t)
    {
        // cout << "Case #" << i+1 << ": ";
        solve();
    }

    return 0;
}
