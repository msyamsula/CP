#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
typedef map<ii, int> miii;
#define imp -(1<<30)

int dp[51][1501];

// int dp(int n, int p, vvi st){
//     // ii key = make_pair(n,p);
//     if(table[n][p] != -1){
//         // cout << "memo" << endl;
//         return table[n][p];
//     }

//     // cout << "calculation" << endl;
//     if (p==0) return table[n][p] = 0;
//     if (n==0) return table[n][p] = imp;

//     int si = n-1;
//     int ans = imp;
//     for(int take=0; take<=min(p, int(st[si].size())-1); take++){
//         ans = max(ans, dp(n-1, p-take, st)+st[si][take]);
//     }

//     return table[n][p] = ans;
// }

void solve(int tc){
    int n,k,p; cin>>n>>k>>p;
    vvi st(n);
    for(int i=0; i<n; i++){
        st[i].push_back(0);
        for(int j=1; j<=k; j++){
            int temp; cin>>temp;
            st[i].push_back(temp+st[i][j-1]);
        }
    }

    // miii mem;
    // memset(dp, -(1<<30), sizeof(dp));
    // for(int i=0; i<=n; i++){
    //     for(int j=0; j<=p; j++){
    //         cout << dp[i][j] << ' ';
    //     }
    //     cout << endl;
    // }
    dp[0][0] = 0;
    for(int i=1; i<=n; i++){
        for(int j=0; j<=p; j++){
            int si = i-1;
            dp[i][j] = imp;
            for(int take=0; take<=min(j, k); take++){
                dp[i][j] = max(dp[i][j], dp[i-1][j-take]+st[si][take]);
            }
        }
    }


    int ans = dp[n][p];
    cout << "Case #" << tc << ": " << ans << endl;
}

int main(){
    int tc; cin>>tc;
    for(int i=0; i<tc; i++){
        solve(i+1);
    }

    return 0;
}