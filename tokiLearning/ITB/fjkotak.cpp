#include<bits/stdc++.h>
using namespace std;
typedef vector<long> vi;
typedef vector<vi> vvi;
#define INF pow(2,50)

void solve(){
    long n,k; cin>>n>>k;
    vi arr(n);
    for(long i=0; i<n; i++){
        cin>>arr[i];
    }

    sort(arr.begin(), arr.end());
    long baskets = n/k;
    // cout << baskets << endl;
    vvi dp(baskets+1, vi(n+1, INF));
    dp[0][0]=0;
    for(long i=1; i<=baskets; i++){
        long start = k*i;
        long basketsLeft = baskets - i;
        long end = n - basketsLeft*k;
        // cout << i << ' ' << start << ' ' << end << endl;
        for (long j=start; j<=end; j++){
            // long basketsLeft = baskets-i;
            // long limit = long((n-j)/basketsLeft);
            // cout << limit << endl;
            // if ( limit < k) break;
            for(long jj=start-k; jj<=n; jj++){
                // cout << i << ' ' << j << ' ' << jj << endl;
                if (j-jj < k){
                    break;
                }
                long value = arr[j-1] - arr[jj];
                dp[i][j] = min(dp[i-1][jj]+value, dp[i][j]);
            }
        }
    }

    // cout << baskets << ' ' << n << endl;
    // for(vi temp : dp){
    //     for(long num : temp){
    //         cout << num << ' ';
    //     }
    //     cout << endl;
    // }
    // cout << endl;
    cout << dp[baskets][n] << endl;
}

int main(){
    int tc; cin>>tc;
    for(int i=0; i<tc; i++){
        solve();
    }

    return 0;
}