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

vi arr;
vvi dp;

int main(){
    arr.resize(0);
    int n,y; cin>>n>>y;
    dp.resize(0); dp.assign(n+1,vi(y+1,MAXI));
    dp[0][0] = 0;
    for(int i=0; i<n; i++){
        int ntemp; cin>>ntemp;
        arr.push_back(ntemp);
    }

    // for(int a : arr){
    //     cout << a << ' ';
    // }
    // cout << endl;

    for(int i=0; i<n; i++){
        for(int j=0; j<=y; j++){
            if (dp[i][j] == MAXI) continue;
            dp[i+1][j] = min(dp[i+1][j], dp[i][j]);
            int ns = j + arr[i];
            if (ns > y || ns < 0) continue;
            dp[i+1][ns] = min(dp[i+1][ns], dp[i][j]+1);
        }
    }

    for(vi temp : dp){
        for(int a : temp){
            cout << a << ' ';
        }
        cout << endl;
    }

    int ans = (dp[n][y] == MAXI) ? -1 : dp[n][y];
    cout << ans << endl;
    return 0;
}
