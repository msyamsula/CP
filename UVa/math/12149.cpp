#include<bits/stdc++.h>
using namespace std;


int dp[103];

void solve(int n){
    if (dp[n] != -1){
        cout << dp[n] << endl;
        return;
    }
    
    for(int i=1; i<=n; i++){
        dp[i] = dp[i-1] + i*i;
    }
}

int main(){
    int n;
    memset(dp, -1, sizeof(dp));
    dp[0] = 0;
    solve(100);
    while(true){
        cin>>n;
        if(n == 0) break;
        cout << dp[n] << endl;
    }

    return 0;
}