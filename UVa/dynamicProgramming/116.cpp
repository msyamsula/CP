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

ll R,C;
vvl arr;
vvl dp;
vl dy = {-1,0,1};
// vvl m;
vl path;

void backtrack(ll row, ll col){
    // cout << row << ' ' << col << endl;
    if (col == 0) return;
    ll minrow = MAXLL;
    for(ll i=0; i<3; i++){
        ll nrow = row+dy[i]; nrow%=R;
        nrow = (nrow < 0) ? nrow+R : nrow;
        if (dp[nrow][col-1]==dp[row][col]-arr[row][col]){
            minrow = min(minrow, nrow);
            // path.push_back(nrow);
            // return backtrack(nrow, col-1);
        }
    }
    path.push_back(minrow);
    return backtrack(minrow, col-1);
}

// void mforward(ll row, ll col){
//     if (col == C-1) return;
//     for(ll i=0; i<3; i++){
//         ll nrow = row+dy[i]; nrow%=R;
//         nrow = (nrow<0) ? nrow+R:nrow;
//         if(m[nrow][col+1] == 1){
//             path.push_back(nrow+1);
//             return mforward(nrow, col+1);
//         }
//     }
// }

void solve(){
    arr.resize(0); dp.resize(0);
    arr.assign(R,vl(C,0)); dp.assign(R,vl(C,MAXLL));
    vvl arrcp=arr;
    for(ll i=0; i<R; i++){
        for( ll j=0; j<C; j++){
            cin>>arrcp[i][j];
            // if (j==0) dp[i][j] = arr[i][j];
        }
    }

    for(ll i=0; i<R; i++){
        for( ll j=0; j<C; j++){
            arr[i][j] = arrcp[i][C-1-j];
            if (j==0) dp[i][j] = arr[i][j];
            // cout << arr[i][j] << ' ';
        }
        // cout << endl;
    }

    for(ll j=0; j<C-1; j++){
        for(ll i=0; i<R; i++){
            for (ll ii=0; ii<3; ii++){
                ll ni = i+dy[ii]; ni%=R;
                ni = (ni<0) ? ni+R : ni;
                dp[ni][j+1] = min(dp[ni][j+1], dp[i][j]+arr[ni][j+1]);
            }
        }
    }
    // ll i=0;
    // for(vl temp : dp){
    //     ll j=0;
    //     for(ll num : temp){
    //         cout << arr[i][j] << '/' << num << ' ';
    //         j++;
    //     }
    //     cout << endl;
    //     i++;
    // }
    // cout << endl;

    // for(ll i=0; i<R; i++){
    //     ans = min(ans, dp[i][C-1]);
    // }

    // m.assign(R, vl(C,0));
    ll ans = MAXLL;
    path.resize(0);
    path.push_back(0);
    for(ll i=0; i<R; i++){
        if (dp[i][C-1] < ans){
            ans = dp[i][C-1];
            path[0] = i;
            // break;
        }
    }
    // cout << path[0] << endl;
    backtrack(path[0], C-1);
    for(ll i=0; i<C; i++){
        cout << path[i]+1 << " \n"[i==C-1];
    }
    cout << ans << endl;
    // for(ll i=path.size()-1; i>=0; i--){
    //     cout << path[i] << " \n"[i==0];
    // }
    // cout << ans << endl;

    // for(vl temp :m){
    //     for(ll num : temp){
    //         cout << num << ' ';
    //     }
    //     cout << endl;
    // }
    // for(ll i=0; i<R; i++){
    //     if (m[i][0] == 1){
    //         path.push_back(i+1);
    //         break;
    //     }
    // }
    // mforward(path[0]-1,0);
    // for(ll i=0; i<path.size(); i++){
    //     cout << path[i] << " \n"[i==path.size()-1];
    // }
    // cout << ans << endl;
}

int main(){
    // int tc; cin>>tc;
    while(cin>>R>>C){
        // cout << "Case #" << i+1 << ": ";
        solve();
    }

    return 0;
}
