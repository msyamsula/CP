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
vs grid;

void solve(){
    grid.resize(0);
    cin>>n>>m;
    grid.assign(n, string(m, 0));
    ll ans = 0;
    for(ll i=0; i<n; i++){
        for(ll j=0; j<m; j++){
            cin>>grid[i][j];
            if (i==n-1 && j==m-1) continue;
            else if (j==m-1 && i!=n-1 && grid[i][j] == 'R') ans++;
            else if (j!=m-1 && i==n-1 && grid[i][j] == 'D') ans++;
        }
    }

    cout << ans << endl;
}

int main(){
    int tc; cin>>tc;
    for(int i=0; i<tc; i++){
        // cout << "Case #" << i+1 << ": ";
        solve();
    }

    return 0;
}
