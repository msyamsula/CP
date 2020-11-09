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

ll r,c;
vvl grid;
vl dy={-1,0,1,0}, dx={0,1,0,-1};

void solve(){
    cin>>r>>c;
    grid.resize(0); grid.assign(r, vl(c, 0));
    for(ll i=0; i<r; i++){
        for(ll j=0; j<c; j++){
            cin>>grid[i][j];
        }
    }

    ll eliminate;
    ll ans = 0;
    do {
        vvl copy; copy.assign(r, vl(c, 0));
        eliminate = 0;
        ll cur_round = 0;
        for(ll i=0; i<r; i++){
            for(ll j=0; j<c; j++){
                if (grid[i][j] == -1) continue;
                cur_round += grid[i][j];
                ll n_sum = 0;
                ll n_tot = 0;
                for(ll ii=0; ii<4; ii++){
                    ll ni = i+dy[ii], nj = j+dx[ii];
                    if (ni<0 || ni>=r || nj < 0 || nj >= c) continue;
                    if (grid[ni][nj] == -1) continue;
                    n_sum += grid[ni][nj];
                    n_tot++;
                }

                if (n_tot == 0){
                    copy[i][j] = grid[i][j];
                    continue;
                }

                double average = (double)n_sum/n_tot;
                if ((double)grid[i][j] < average){
                    eliminate++;
                    copy[i][j] = -1;
                } else {
                    copy[i][j] = grid[i][j];
                }
            }
        }

        ans += cur_round;
        grid = copy;

        for(vl arr : grid){
            for(ll num : arr){
                cout << num << ' ';
            }
            cout << endl;
        }
        cout << "cur_round: " << cur_round << endl;
        cout << "eliminate: " << eliminate << endl;

    } while (eliminate > 0);

    cout << ans << endl;
}

int main(){
    int tc; cin>>tc;
    for(int i=0; i<tc; i++){
        cout << "Case #" << i+1 << ": ";
        solve();
    }

    return 0;
}
