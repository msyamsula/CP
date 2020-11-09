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

ll n,m;
vvl grid;

void solve(){
    cin>>n>>m;
    grid.resize(0);
    grid.assign(n, vl(m, 0));
    vvl row; row.resize(n);
    vvl col; col.resize(m);
    for(ll i=0; i<n; i++){
        for(ll j=0; j<m; j++){
            cin>>grid[i][j];
            if (grid[i][j]){
                row[i].push_back(j);
                col[j].push_back(i);
            }
        }
    }

    // cout << "grid: " << endl;
    // for(vl arr: grid){
    //     for(ll num : arr){
    //         cout << num << ' ';
    //     }
    //     cout << endl;
    // }
    // cout << endl;

    // cout << "row: " << endl;
    // for(vl arr: row){
    //     for(ll num : arr){
    //         cout << num << ' ';
    //     }
    //     cout << endl;
    // }
    // cout << endl;

    // cout << "col: " << endl;
    // for(vl arr: col){
    //     for(ll num : arr){
    //         cout << num << ' ';
    //     }
    //     cout << endl;
    // }
    // cout << endl;

    ll tot = 0;
    for(ll i=0; i<n; i++){
        for(ll j=0; j<m; j++){
            if (grid[i][j]) continue;
            ll add = 0;
            auto next_col = lower_bound(row[i].begin(), row[i].end(), j+1);
            if (next_col != row[i].end()) add++;
            auto prev_col = upper_bound(row[i].begin(), row[i].end(), j-1);
            if (!(prev_col == row[i].begin())) add++;
            auto next_row = lower_bound(col[j].begin(), col[j].end(), i+1);
            if (next_row != col[j].end()) add++;
            auto prev_row = upper_bound(col[j].begin(), col[j].end(), i-1);
            if (!(prev_row == col[j].begin())) add++;

            // cout << i << ", " << j << ": " << add << endl;
            tot+=add;
        }
    }

    cout << tot << endl;
}

int main(){
    solve();
    // int tc; cin>>tc;
    // for(int i=0; i<tc; i++){
    //     cout << "Case #" << i+1 << ": ";
    // }

    return 0;
}
