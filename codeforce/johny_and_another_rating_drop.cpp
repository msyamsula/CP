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

map<ll, ll> mem;
ll n;

void solve(){
    cin>>n;
    ll ans = 0;
    for(ll i=0; i<63; i++){
        ll cb = (1ll<<i);
        if ( (cb&n) != 0) ans += mem[cb];
    }

    cout << ans << endl;
}

int main(){
    for(ll p=0; p<63; p++){
        mem[(1ll<<(p))] = (1ll<<(p+1))-1;
    }

    int tc; cin>>tc;
    for(int i=0; i<tc; i++){
        // cout << "Case #" << i+1 << ": ";
        solve();
    }

    return 0;
}
