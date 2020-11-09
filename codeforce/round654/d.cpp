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

ll n,k;
vvl grid;

void solve(){
    cin>>n>>k;
    grid.resize(0); grid.assign(n, vl(n, 0));
    ll max_offset = (k-1)/n;

    if (k%n == 0) cout << 0 << endl;
    else cout << 2 << endl;
    
    for(ll j=0; j<=max_offset; j++){
        for(ll i=0; i<n; i++){
            if (k==0)break;
            grid[i][(j+i)%n] = 1;
            k--;
        }
    }

    for(vl a : grid){
        for(ll i=0; i<a.size(); i++){
            cout << a[i];
        }
        cout << endl;
    }
}

int main(){
    int tc; cin>>tc;
    for(int i=0; i<tc; i++){
        // cout << "Case #" << i+1 << ": ";
        solve();
    }

    return 0;
}
