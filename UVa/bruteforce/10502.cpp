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
vvl p_sum;

void solve(){
    cin>>C;
    grid.resize(0); grid.assign(R, vl(C, 0));
    p_sum.resize(0); p_sum.assign(R+1, vl(C+1, 0));
    for(ll i=0; i<R; i++){
        string temp; cin>>temp;
        for(ll j=0; j<C; j++){
            grid[i][j] = (ll)temp[j]-'0';
            p_sum[i+1][j+1] = p_sum[i][j+1] + p_sum[i+1][j] + grid[i][j] - p_sum[i][j];
        }
    }

    ll ans = 0;
    for(ll i=0; i<R; i++){
        for(ll j=0; j<C; j++){
            for(ll ii=i; ii<R; ii++){
                for(ll jj=j; jj<C; jj++){
                    ll c_sum = p_sum[ii+1][jj+1]-p_sum[ii+1][j] - p_sum[i][jj+1] +p_sum[i][j];
                    ll area = (jj-j+1)*(ii-i+1);
                    if (area == c_sum) ans++;
                }
            }
        }
    }

    cout << ans << endl;
}

int main(){
    while(cin>>R){
        if(!R) break;
        solve();
    }
    // int tc; cin>>tc;
    // for(int i=0; i<tc; i++){
    //     cout << "Case #" << i+1 << ": ";
    //     solve();
    // }

    return 0;
}
