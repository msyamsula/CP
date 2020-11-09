#include<bits/stdc++.h>
using namespace std;

typedef vector<long long> vi;
typedef vector<vi> vvi;
#define imp 9.223372e+18

void solve(int tc){
    long long k,n; cin>>k>>n;
    vi pos(n), build(n);
    for(long long i=0; i<n; i++){
        cin>>pos[i];
    }
    
    for(long long i=0; i<n; i++){
        cin>>build[i];
    }

    // vi price(n,0);
    long long dp[n+1][k+1];

    long long ans = imp;
    for (long long wi=0; wi<n; wi++){
        for(long long i=0; i<=k; i++){
            dp[0][i] = imp;
        }

        dp[0][0] = build[wi];
        long long pivot = pos[wi];

        for(long long i=1; i<=n; i++){
            for(long long b=0; b<=k; b++){
                if (b==0){
                    dp[i][b] = dp[0][0];
                    continue;
                }
                long long idx = i-1;
                if (pos[idx] == pivot){
                    dp[i][b] = dp[i-1][b];
                    continue;
                }

                dp[i][b] = min(dp[i-1][b-1] + build[idx] + abs(pos[idx] - pivot), dp[i-1][b]);
            }
        }

        cout << endl;
        for(long long i=0; i<=n; i++){
            for(long long j=0; j<=k; j++){
                cout << dp[i][j] << ' ';
            }
            cout << endl;
        }
        ans = min(ans, dp[n][k]);
    }

    cout << "Case #" << tc << ": " << ans << endl;
    
}

int main(){
    int tc; cin>>tc;
    for(int i=0; i<tc; i++){
        solve(i+1);
    }

    return 0;
}