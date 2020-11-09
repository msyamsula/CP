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

ll K;
vector<vvl> posibilities;
vvl score;
vvl status;
ll sz = 8;

bool safe(ll row, ll col){
    for(ll i=0; i<sz; i++){
        // if (i==row) continue;
        if (status[i][col] == 1){
            // cout << row << ' ' << col << ' ' << "break by " << i << ' ' << col << endl;
            return 0;
        }
    }

    for(ll i=0; i<sz; i++){
        // if (i==col) continue;
        if (status[row][i] == 1){
            // cout << row << ' ' << col << ' ' << "break by " << row << ' ' << i << endl;
            return 0;
        }
    }

    for(ll i=1; i<sz; i++){
        ll nrow = row+i, ncol = col+i;
        if (nrow<0 || nrow>=sz || ncol < 0 || ncol >= sz) break;
        if (status[nrow][ncol] == 1){
            // cout << row << ' ' << col << ' ' << "break by " << nrow << ' ' << ncol << endl;
            return 0;
        }
    }

    for(ll i=1; i<sz; i++){
        ll nrow = row-i, ncol = col-i;
        if (nrow<0 || nrow>=sz || ncol < 0 || ncol >= sz) break;
        if (status[nrow][ncol] == 1){
            // cout << row << ' ' << col << ' ' << "break by " << nrow << ' ' << ncol << endl;
            return 0;
        }
    }

    for(ll i=1; i<sz; i++){
        ll nrow = row-i, ncol = col+i;
        if (nrow<0 || nrow>=sz || ncol < 0 || ncol >= sz) break;
        if (status[nrow][ncol] == 1){
            // cout << row << ' ' << col << ' ' << "break by " << nrow << ' ' << ncol << endl;
            return 0;
        }
    }

    for(ll i=1; i<sz; i++){
        ll nrow = row+i, ncol = col-i;
        if (nrow<0 || nrow>=sz || ncol < 0 || ncol >= sz) break;
        if (status[nrow][ncol] == 1){
            // cout << row << ' ' << col << ' ' << "break by " << nrow << ' ' << ncol << endl;
            return 0;
        }
    }

    return 1;
}

void search(ll row){
    // cout << row << endl;
    // for(vl temp : status){
    //     for(ll num : temp){
    //         cout << num << ' ';
    //     }
    //     cout << endl;
    // }
    if (row == sz){
        posibilities.push_back(status);
        // for(vl temp : status){
        //     for (ll num : temp){
        //         cout << num << ' ';
        //     }
        //     cout << endl;
        // }
        // cout << endl;
        return;
    }

    for(ll col=0; col<sz; col++){
        if(safe(row, col)){
            status[row][col] = 1;
            search(row+1);
            status[row][col] = 0;
        }
    }
}

void solve(){
    score.resize(0);
    score.assign(sz, vl(sz, 0));
    for(ll row=0; row<sz; row++){
        for(ll col=0; col<sz; col++){
            cin>>score[row][col];
            // cout << score[row][col] << ' ';
        }
        // cout << endl;
    }

    ll ans = 0;
    for(ll p=0; p<posibilities.size(); p++){
        ll cur_score = 0;
        for(ll row=0; row<sz; row++){
            for(ll col=0; col<sz; col++){
                cur_score += posibilities[p][row][col]*score[row][col];
                // cout << posibilities[p][row][col] << ' ';
            }
            // cout << endl;
        }
        // cout << cur_score << endl;
        ans = max(ans, cur_score);   
    }

    cout << setw(5) << ans << endl;
}

int main(){
    posibilities.resize(0);
    vvl grid; grid.assign(sz, vl(sz, 0));
    status = grid;
    search(0);
    // cout << posibilities.size() << endl;
    // for(vvl temp : posibilities){
    //     for(vl row : temp){
    //         for(ll num : row){
    //             cout << num << ' ';
    //         }
    //         cout << endl;
    //     }
    //     cout << endl;
    // }
    int K; cin>>K;
    for(int i=0; i<K; i++){
        // cout << "Case #" << i+1 << ": ";
        solve();
    }

    return 0;
}
