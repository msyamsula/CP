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
vl dx={0,1,0,-1}, dy={-1,0,1,0};

void solve(){
    ll R,C; cin>>R>>C;
    grid.resize(0); grid.assign(R, vl(C, 0));
    for(ll i=0; i<R; i++){
        for(ll j=0; j<C; j++){
            cin>>grid[i][j];
        }
    }

    ll add = 0;
    for(ll k=0; k<1; k++){
        for(ll i=0; i<R; i++){
            for(ll j=0; j<C; j++){
                bool nearSea = 0;
                ll ch = grid[i][j];
                ll nh = MAXLL;
                for(ll ii=0; ii<4; ii++){
                    ll ni = i+dy[ii], nj=j+dx[ii];
                    if (ni < 0 || ni>=R || nj<0 || nj>=C){
                        nearSea = 1;
                        break;
                    }
                    nh = min(nh, grid[ni][nj]);
                }

                if(!nearSea){
                    if (nh >= ch){
                        add += (nh-ch);
                        grid[i][j]=nh;
                    }
                    // cout << i << ' ' << j << ' ' << grid[i][j] << ' ' << add << endl;
                }
            }
        }
        for(vl temp : grid){
            for( ll num : temp){
                cout << num << ' ';
            }
            cout << endl;
        }
    }


    cout << add << endl;
}

int main(){
    int tc; cin>>tc;
    for(int i=0; i<tc; i++){
        cout << "Case #" << i+1 << ": ";
        solve();
    }

    return 0;
}
