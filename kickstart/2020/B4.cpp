#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;

void solve(int tc){
    // int ans = 0;
    int w,h,l,u,r,d; cin>>w>>h>>l>>u>>r>>d;
    vvi grid(h, vi(w, 1));
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            if (l-1<=j && j<=r-1 && u-1<=i && i<=d-1) grid[i][j]=0;
        }
    }

    vvi dp(h, vi(w, 0));
    dp[0][0] = 1;
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            if (j==w-1 && i+1<h && grid[i][j] == 1) dp[i+1][j] += dp[i][j];
            else if (i==h-1 && j+1<w && grid[i][j] == 1) dp[i][j+1] += dp[i][j];
            else if (grid[i][j] == 1){
                int nr = i+1, nc = j+1;
                if (nr<h){
                    dp[nr][j] += dp[i][j];
                } 

                if (nc<w){
                    dp[i][nc] += dp[i][j];
                }

            }
        }
    }

    double total = 0;
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            if (grid[i][j] == 0) total += dp[i][j];
        }
    }

    for(vi temp: dp){
        for(int num : temp){
            cout << num << ' ';
        }
        cout << endl;
    }

    cout << endl;

    for(vi temp: grid){
        for(int num : temp){
            cout << num << ' ';
        }
        cout << endl;
    }
    cout << endl;
    cout << "Case #" << tc << ": " << setprecision(5) << fixed << double(dp[h-1][w-1])/(total+dp[h-1][w-1]) << endl;
}

int main(){
    int tc; cin>>tc;
    for(int i=0;i<tc; i++){
        solve(i+1);
    }

    return 0;
}