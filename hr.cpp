#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef map<string, int> msi;

int main(){
    vi arr = {1,2,2,1};
    int n = arr.size();
    vi dp(n, 0);
   
    vi ncoin(n,1);
    vi coin(n, 0);
    coin[0] = 1;
    dp[0]=1;
    int limit;
    for(int i=1; i<n; i++){
        if (arr[i]>arr[i-1]){
            coin[i] = coin[i-1]+1;
            dp[i] = dp[i-1] + coin[i];
            limit = coin[i];
        } else if (arr[i]<arr[i-1]){
            coin[i] = coin[i-1]-1;
            if (coin[i] == 0){
                coin[i] = 1;
                if (coin[i] == coin[i-1]) ncoin[i] = ncoin[i-1]+1;
                if (ncoin[i] >= limit) dp[i] = dp[i-1]+coin[i]+ncoin[i];
                else dp[i] = dp[i-1]+ncoin[i];
            } else {
                coin[i] = 1;
                dp[i] = dp[i-1]+coin[i];
            }
        } else if (arr[i] == arr[i-1]){
            coin[i] = 1;
            limit = 1;
            dp[i] = dp[i-1]+1;
        }
    }


    for (int i=0; i<n; i++){
        cout << dp[i] << ' ';
    }
    cout << endl;
    


    return 0;
} 