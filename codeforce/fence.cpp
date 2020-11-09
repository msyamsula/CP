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
vl ps;

void solve(){
    cin>>n>>k;
    ps.resize(0); ps.assign(n+1, 0);
    for(ll i=0; i<n; i++){
        ll temp; cin>>temp;
        ps[i+1] = ps[i] + temp;
    }

    ll ans = 0;
    ll min_sum = MAXLL;
    for(ll i=0; i<=n-k; i++){
        if (ps[i+k]-ps[i] < min_sum){
            ans = i;
        }
        min_sum = min(min_sum, ps[i+k]-ps[i]);
    }

    cout << ans+1 << endl;
}

int main(){
    solve();

    return 0;
}
