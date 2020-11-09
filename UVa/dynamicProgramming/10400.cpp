#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

void print_opt(int n, int target, vvi dp, vi number, string &ans){
    // cout << ans << endl;
    if (n==0) return;

    if (n==1){
        ans = to_string(target)+ans;
        return;
    }

    int in = n-1;
    int cn = number[in];
    string mark = "+-/*";
    vi pn = {target-cn, target+cn, target*cn, target/cn};
    int sz = (target%cn == 0) ? 4 : 3;
    int choice = 1;
    // int prev;
    for(int i=0; i<sz; i++){
        // cout << pn[i] << ' ';
        if (pn[i]<-32000 || pn[i]>32000) continue;
        int ii = pn[i]+32000;
        if (dp[n-1][ii] == 1){
            choice = i;
            // cout << "inside " << choice << endl;
            break;
        }
    }
    // for(int i=0;i<4;i++){
    //     if (prev-cn==target) choice = 1;
    //     else if (prev+cn==target) choice = 0;
    //     else if (prev*cn==target) choice = 3;
    //     else choice = 2;
    // }
    // cout << endl;
    // cout << "cm " << ' ' << choice << ' ' << mark[choice] << endl;
    ans = mark[choice]+to_string(cn)+ans;
    print_opt(n-1, pn[choice], dp, number, ans);
}

void solve(){
    int n; cin>>n;
    vi number(n);
    for(int i=0; i<n; i++){
        cin>>number[i];
    }
    int target; cin>>target;

    vi zeros(64005, 0);
    vvi dp(105,zeros);

    for (int i=0; i<64005; i++){
        dp[0][i] = 0;
    }

    int i = 0+32000;
    dp[0][i] = 1;

    for(int i=1;i<=n;i++){
        int cn = number[i-1];
        if (i==1){
            int jj = cn + 32000; 
            dp[i][jj] = 1;
            // dp[0] = dp[1];
            continue;
        }

        for(int j=0; j<64005; j++){
            int t = j-32000;
            int pn[] = {t-cn, t+cn, t*cn, t/cn};
            int sz = (t%cn == 0) ? 4 : 3; 
            dp[i][j] = 0;
            for(int ii=0; ii<sz; ii++){
                if (pn[ii] < -32000 || pn[ii] > 32000) continue;
                dp[i][j] = dp[i][j] | dp[i-1][pn[ii]+32000];
            }
        }
        // dp[0] = dp[1];
    }
    // cout << dp[2][12+32000] << endl;
    string ans = '='+to_string(target);
    if (dp[n][target+32000] == 1){
        print_opt(n,target,dp,number,ans);
        cout << ans << endl;
    } else {
        cout << "NO EXPRESSION" << endl;
    }
    // string ans = (dp[n][target+32000] == 1) ? "possible" : "NO EXPRESSION";
    // cout << ans << endl;

    // for(int i=0; i<=n; i++){
    //     for(int j=-10+32000; j<=15+32000; j++){
    //         cout << dp[i][j] << ' ';
    //     }
    //     cout << endl;
    // }
}

int main(){
    int tc; cin>>tc;
    for(int i=0; i<tc; i++){
        solve();
    }

    return 0;
}