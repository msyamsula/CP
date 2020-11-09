#include<bits/stdc++.h>
using namespace std;
typedef vector<long> vl;

void solve(int n){
    vl numbers(n);
    for(int i=0; i<n; i++){
        cin>>numbers[i];
    }

    vl prefix(n+1);
    prefix[0] = 0;
    for(int i=1; i<=n; i++){
        prefix[i] = max(long(0), prefix[i-1]+numbers[i-1]);
    }

    vl dp(n);
    dp[0] = numbers[0];
    // int start = 0;
    for(int i=1; i<n; i++){
        dp[i] = max(dp[i-1], numbers[i]);
        dp[i] = max(dp[i], prefix[i+1]);
        // if (dp[i] == numbers[i]) start = i;
    }

    // cout << dp[n-1] << endl;
    if (dp[n-1] == 0){
        cout << "Losing streak." << endl;
    } else {
        cout << "The maximum winning streak is " << dp[n-1] << '.' << endl;
    }

}

int main(){
    int n;
    while(cin>>n){
        if (n==0) break;
        solve(n);
    }
    

    return 0;
}