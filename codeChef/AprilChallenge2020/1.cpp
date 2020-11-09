#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
#define MAX (1<<30)
#define MIN -(1<<30)

void solve(){
    int n;
    // n = 2000; 
    cin>>n;
    vi price(n);
    for(int i=0; i<n; i++){
        // price[i] = rand()%1000000000;
        cin>>price[i];
    }
    sort(price.begin(), price.end());
    int ans = 0;
    int d = 0;
    for(int i=price.size()-1; i>=0; i--){
        cout << price[i] << ' ';
        ans += max(0,price[i] - d);
        ans = (ans >= 1000007) ? ans-1000007 : ans;
        d++;
    }

    cout << ans << endl;
    // cout << "tes" << endl;
    // for (int i=0; i<n; i++){
    //     cout << price[i] << ' ';
    // }
    // cout << endl;
    // int dp[n][n];
    // vvi dp(n, vi(n,0));
    // for(int i=0; i<n; i++){
    //     dp[i][i] = max(0,price[i] - (n-1));
    // }

    // for(int i=1; i<n; i++){
    //     for(int j=0; j+i<n; j++){
    //         int ii = j, jj = i+j;
    //         cout << ii << ' ' << jj << endl;
    //         // if (ii<0 || ii>=n || jj<0 || jj>=n) continue;
    //         dp[ii][jj] = MIN;
    //         for(int choice=ii; choice<=jj; choice++){
    //             int value = ((ii==choice) ? 0 : dp[ii][choice-1]) + ((choice==jj) ? 0 : dp[choice+1][jj]) + max(0, price[choice]-n+jj-ii+1);
    //             value = (value >= 1000007) ? value-1000007 : value;
    //             dp[ii][jj] = max(dp[ii][jj], value);
    //         }
    //     }
    // }

    // // for(int i=0; i<n; i++){
    // //     for(int j=0; j<n; j++){
    // //         cout << dp[i][j] << ' ';
    // //     }
    // //     cout << endl;
    // // }

    // cout << dp[0][n-1] << endl;
}

int main(){
    int tc; cin>>tc;
    for(int i=0; i<tc; i++){
        solve();
    }

    return 0;
}