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

ll R,C;
vvl grid;
vvl psum;


void solve(){
    grid.resize(0); grid.assign(R, vl(C, 0));
    psum.resize(0); psum.assign(R+1, vl(C+1, 0));
    ll p=0;
    vs grid_str;
    for(ll i=0; i<R; i++){
        string row; cin>>row;
        grid_str.push_back(row);
    }

    for(ll i=0; i<R; i++){
        for(ll j=0; j<C; j++){
            grid[i][j] = grid_str[i][j]-'0';
            // cin>>grid[i][j];
            psum[i+1][j+1] = psum[i+1][j] + psum[i][j+1] + grid[i][j] - psum[i][j];
            // cout << grid[i][j] << ' ';
            if (grid[i][j] == 1) p++;
        }
        // cout << endl;
    }


    ll ans = MAXLL;
    for(ll row=1; row*row<=p; row++){
        if (p%row != 0) continue;
        ll col = p/row;
        for(ll i=0; i<R; i++){
            if (i+row > R) break;
            for(ll j=0; j<C; j++){
                if (j+col>C) break;
                ll inside = psum[i+row][j+col] - psum[i+row][j] - psum[i][j+col] + psum[i][j];
                ll outside = p - inside;
                if (outside == 0){
                    cout << 0 << endl;
                    return;
                }
                ans = min(ans, outside);
            }
        }

        for(ll i=0; i<R; i++){
            if (i+col > R) break;
            for(ll j=0; j<C; j++){
                if (j+row>C) break;
                ll inside = psum[i+col][j+row] - psum[i+col][j] - psum[i][j+row] + psum[i][j];
                ll outside = p - inside;
                if (outside == 0){
                    cout << 0 << endl;
                    return;
                }
                ans = min(ans, outside);
            }
        }
    }
    if (ans == MAXLL){
        cout << -1 << endl;
        return;
    }

    cout << ans << endl;

    // cout << p << endl;

    // ll ans = MAXLL;
    // for(ll i=0; i<R; i++){
    //     for(ll j=0; j<C; j++){
    //         for(ll ii=i; ii<R; ii++){
    //             for(ll jj=j; jj<C; jj++){
    //                 ll area = (jj+1-j)*(ii+1-i);
    //                 // cout << area << endl;
    //                 if (area<p || area>p) continue;
    //                 ll sum = psum[ii+1][jj+1]-psum[ii+1][j] - psum[i][jj+1] + psum[i][j];
    //                 if (sum == area && sum == p){
    //                     cout << 0 << endl;
    //                     return;
    //                 }
    //                 ll outside = p - sum;
    //                 if (outside == 0) continue;
    //                 ll slot = area - sum;
    //                 ll move = min(slot, outside);
    //                 // cout << area << ' ' << slot << endl;
    //                 ans = min(ans, move);
    //             }
    //         }
    //     }
    // }
    
    // cout << ans << endl;

}

int main(){
    while(cin>>R>>C){
        solve();
    }
    // int tc; cin>>tc;
    // for(int i=0; i<tc; i++){
    //     cout << "Case #" << i+1 << ": ";
    //     solve();
    // }

    return 0;
}
