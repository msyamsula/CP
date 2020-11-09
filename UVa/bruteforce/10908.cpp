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

ll R, C, Q;
vs grid;

void solve(){
    cin>>R>>C>>Q;
    cout<<R << ' ' << C << ' ' << Q << endl;
    grid.resize(0); grid.assign(R, string(C, ' '));
    for(ll i=0; i<R; i++){
        cin>>grid[i];
    }

    for(ll i=0; i<Q; i++){
        ll qi, qj; cin>>qi>>qj;
        ll ans = 1;
        char master = grid[qi][qj];
        for(ll sz=3; sz<=min(R,C); sz+=2){
            ll substract = sz/2;
            ll li = qi-substract, lj=qj-substract;
            ll ri = qi+substract, rj = qj+substract;
            if (li<0 || li>=R || ri<0 || ri >=R) break;
            if (lj<0 || lj>=C || rj<0 || rj >=C) break;
            ll pas = 1;
            for(ll ii=li; ii<=ri; ii++){
                for(ll jj=lj; jj<=rj; jj++){
                    if(grid[ii][jj] != master){
                        pas = 0;
                    }
                }
            }

            if(pas) ans = sz;
        }
        cout << ans << endl;
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
