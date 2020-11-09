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

ll q,n;
vl ufd, st;

ll parent(ll u){
    if (ufd[u]<0) return u;
    return parent(ufd[u]);
}

void join(ll u, ll v){
    ll pu = parent(u), pv = parent(v);
    if (pv == pu) return;

    if (ufd[pu]<=ufd[pv]){
        ufd[pu]+=ufd[pv];
        ufd[pv]=pu;
    } else {
        ufd[pv]+=ufd[pu];
        ufd[pu]=pv;
    }
}

void solve(){
    cin>>q>>n;
    ufd.resize(0); ufd.assign(n, -1);
    st.resize(0); st.assign(4*n, 0);
    for(ll i=0; i<q; i++){

    }
}

int main(){
    solve();

    return 0;
}
