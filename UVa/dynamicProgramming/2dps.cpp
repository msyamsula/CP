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

void solve(){

}

vvl ps2d;
vvl mat;

int main(){
    ll n; cin>>n;
    ps2d.resize(0); ps2d.assign(n+1, vl(n+1, 0));
    mat.resize(0); mat.assign(n, vl(n,0));
    for(ll i=0; i<n; i++){
        for(ll j=0; j<n; j++){
            cin>>mat[i][j];
            ps2d[i+1][j+1] = mat[i][j] + ps2d[i][j+1] + ps2d[i+1][j] - ps2d[i][j];
        }
    }


    ll q; cin>>q;
    for(ll i=0; i<q; i++){
        ll x1,y1,x2,y2; cin>>x1>>y1>>x2>>y2;
        ll ans = ps2d[y2+1][x2+1] - ps2d[y2+1][x1] - ps2d[y1][x2+1] + ps2d[y1][x1];
        cout << ans << endl;
    }
    // int tc; cin>>tc;
    // for(int i=0; i<tc; i++){
    //     cout << "Case #" << i+1 << ": ";
    //     solve();
    // }

    // return 0;
}
