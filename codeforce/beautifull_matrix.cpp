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

void solve(){
    grid.resize(0);
    grid.assign(5, vl(5,0));
    ll r, c;
    for(ll i=0; i<5; i++){
        for(ll j=0; j<5; j++){
            cin>>grid[i][j];
            if (grid[i][j]){
                r = i;
                c = j;
            }
        }
    }

    ll step = abs(2-c) + abs(2-r);
    cout << step << endl;
}

int main(){
    // int tc; cin>>tc;
    ll tc=1;
    for(int i=0; i<tc; i++){
        // cout << "Case #" << i+1 << ": ";
        solve();
    }

    return 0;
}
