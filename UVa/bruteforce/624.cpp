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

ll N, len;
vl ans;
vvl dp;
vl arr;

void backtrack(ll row, ll col){
    // cout << row << ' ' << col << endl;
    if (row == 0) return;
    ll idx = row-1, prev_col = col - arr[idx];
    if (prev_col <= N && prev_col >= 0){
        if (dp[row-1][prev_col] == 1){
            ans.push_back(arr[idx]);
            return backtrack(row-1, col-arr[idx]);
        }
    }
    
    backtrack(row-1, col);
}

void solve(){
    arr.resize(0);
    for(ll i=0; i<len; i++){
        ll temp; cin>>temp;
        arr.push_back(temp);
    }

    dp.resize(0);
    dp.assign(len+1, vl(N+1, 0));
    dp[0][0] = 1;
    for(ll i=0; i<len; i++){
        for(ll j=0; j<=N; j++){
            if (dp[i][j] == 0) continue;
            dp[i+1][j] = 1;
            if (j+arr[i] <= N) dp[i+1][j+arr[i]] = 1;
        }
    }

    ans.resize(0);
    ll sum = 0;
    for(ll i=N; i>=0; i--){
        if(dp[len][i] == 1){
            backtrack(len, i);
            sum = i;
            break;
        }
    }

    for(ll i=ans.size()-1; i>=0; i--){
        if (i!=ans.size()-1) cout << ' ';
        cout << ans[i];
    }
    cout << " sum:" << sum << endl;

    // for(vl temp:dp){
    //     for(ll num : temp){
    //         cout << num << ' ';
    //     }
    //     cout << endl;
    // }
    // cout << endl;
}

int main(){
    while(cin>>N>>len){
        solve();
    }
    // int tc; cin>>tc;
    // for(int i=0; i<tc; i++){
    //     cout << "Case #" << i+1 << ": ";
    //     solve();
    // }

    return 0;
}
