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
vl arr, ps, ps_aksen;

void solve(){
    // cin>>n>>m;
    if (!n && !m) return;
    arr.resize(0);
    ps.resize(0); ps.assign(n+2, 0);
    ps_aksen.resize(0); ps_aksen.assign(n+2, 0);
    vl zonk(n+2, 0);
    for(ll i=0; i<n; i++){
        ll temp; cin>>temp;
        arr.push_back(temp);
    }
    // cout << "n: " <<n << endl;
    // cout << "m: " <<m << endl;
    // cout << "arr: ";
    // for(ll i=0; i<n; i++){
    //     cout << arr[i] << ' ';
    // }
    // cout << endl;

    ll ans = -MAXLL;

    for(ll i=0; i<n; i++){
        ll cur_r = 0;
        for(ll j=0; j<=i; j++){
            if (j==0){
                ps[j+1] = (ps_aksen[j+1]+arr[i])%m;
            } else {
                ps[j+1] = (ps_aksen[j+1]%m)+(arr[i]*ps_aksen[j])%m;
                ps[j+1] %= m;
            }
            cur_r += ps[j+1]; cur_r%=m;
        }
        // cout << "cur_r: " << cur_r << endl;
        // ans = max(cur_r, ans);
        if (i==n-1){
            for(ll j=1; j<=n; j++){
                ans = max(ans, ps[j]);
            }
        }
        // r = cur_r;
        ps_aksen = ps;
        ps = zonk;
        // cout << "ps: ";
        // for(ll j=0; j<=i+1; j++){
        //     cout << ps[j] << ' ';
        // }
        // cout << endl;

        // cout << "ps_aksen: ";
        // for(ll j=0; j<=i+1; j++){
        //     cout << ps_aksen[j] << ' ';
        // }
        // cout << endl;
    }

    cout << ans << endl;
    
}

int main(){
    // int tc; cin>>tc;
    while(cin>>n>>m){
        // cout << "Case #" << i+1 << ": ";
        solve();
    }

    return 0;
}
