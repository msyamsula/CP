#include<bits/stdc++.h>
using namespace std;
typedef vector<long> vl;

void solve(){
    int a,b,c; cin>>a>>b>>c;
    long n = a*b*c;
    vl numbers(n);
    vl prefix(n+1,0);
    prefix[0] = 0;
    for(long i=0; i<n; i++){
        cin>>numbers[i];
        prefix[i+1] = max(long(0), prefix[i] + numbers[i]);
    }

    vl dp(n);
    dp[0] = numbers[0];
    for(long i=1; i<n; i++){
        dp[i] = max(dp[i-1], prefix[i+1]);
    }

    cout << dp[n-1] << endl;
    // for(long num : dp){
    //     cout <<num << ' ';
    // }
    // cout << endl;
}

int main(){
    int tc; cin>>tc;
    for(int i=0; i<tc; i++){
        solve();
    }

    return 0;
}