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

ll n;
vvl grid;

void solve(){
    grid.resize(0);
    cin>>n;
    grid.assign(2, vl(n, 0));
    for(ll i=0; i<n; i++){
        cin>>grid[0][i];
    }
    for(ll i=0; i<n; i++){
        cin>>grid[1][i];
    }

    // for(vl arr: grid){
    //     for(ll num : arr){
    //         cout << num << ' ';
    //     }
    //     cout << endl;
    // }
    // cout << endl;

    for(ll j=1; j<n; j++){
        for(ll i=0; i<2; i++){
            ll ni = (i+1)%2;
            if (j-2>=0) grid[i][j] += max(grid[ni][j-1], grid[ni][j-2]);
            else if (j-1>=0) grid[i][j] += grid[ni][j-1];
        }
    }

    // for(vl arr: grid){
    //     for(ll num : arr){
    //         cout << num << ' ';
    //     }
    //     cout << endl;
    // }

    cout << max(grid[0][n-1], grid[1][n-1]) << endl;
}

int main(){
    solve();
    // int tc; cin>>tc;
    // for(int i=0; i<tc; i++){
    //     cout << "Case #" << i+1 << ": ";
    // }

    return 0;
}
