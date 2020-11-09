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

vvl grid;
ll n;
vl guess;
bool found;

void search(ll row, ll col){
    // cout << row << ' ' << col << endl;
    if (row > 0){
        ll sum = 0;
        for(ll num : grid[row-1]) sum += num;
        if (sum != guess[row-1]) return;
    }

    if (found) return;

    if (row == n){
        found = 1;
        // cout << "grid: " << endl;
        // for(vl arr : grid){
        //     for(ll num : arr){
        //         cout << num << ' ';
        //     }
        //     cout << endl;
        // }
        // cout << endl;
        return;
    }


    if (row == col){
        if (col+1<n) return search(row, col+1);
        else return search(row+1,row+1);
    }
    for(ll ii=0; ii<3; ii++){
        ll score, other;
        if (ii == 0){
            score = 3; other = 0;
        } else if(ii == 1){
            score = 1; other = 1;
        } else if (ii == 2){
            score = 0; other = 3;
        }

        grid[row][col] = score;
        grid[col][row] = other;
        if (col+1 < n) search(row, col+1);
        else search(row+1, row+1);
        grid[row][col] = 0;
        grid[col][row] = 0;
    }
}

void solve(){
    cin>>n;
    guess.resize(0); guess.assign(n,0);
    for(ll i=0; i<n; i++){
        cin>>guess[i];
    }
    grid.resize(0); grid.assign(n, vl(n, 0));
    // cout << "test case" << endl;
    found = 0;
    search(0,0);
    cout << ((found)?"YES":"NO") << endl;
}

int main(){
    int tc; cin>>tc;
    for(int i=0; i<tc; i++){
        // cout << "Case #" << i+1 << ": ";
        solve();
    }

    return 0;
}
