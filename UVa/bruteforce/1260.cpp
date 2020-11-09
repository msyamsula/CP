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

vl st;

void update(ll p, ll a, ll b, ll val){
    if (b<val || a>val) return;
    else if (val<=a && b<=val){
        st[p]++;
        return;
    }
    ll mid = (a+b)/2;
    update(2*p, a, mid, val); update(2*p+1, mid+1, b, val);
    st[p] = st[2*p]+st[2*p+1];
}

ll rsq(ll p, ll a, ll b, ll x, ll y){
    if(b<x || a>y) return 0;
    else if (x<=a && b<=y) return st[p];

    ll mid = (a+b)/2;
    ll left = rsq(2*p, a, mid, x, y), right = rsq(2*p+1, mid+1, b, x, y);
    return left+right;
}

void solve(){
    ll sz = 5000;
    st.resize(0); st.assign(4*(sz+1), 0);
    ll n; cin>>n;
    ll ans = 0;
    for(ll i=0; i<n; i++){
        ll ntemp; cin>>ntemp;
        // cout << ntemp << endl;
        update(1,0,(sz+1),ntemp);
        if (i>0){
            ll b = rsq(1,0,sz+1,1,ntemp);
            // cout << ntemp << ' ' << b-1 << endl;
            ans += b-1;
        }
        // for(ll num : st){
        //     cout << num << ' ';
        // }
        // cout << endl;
    }
    cout << ans << endl;
}

int main(){
    int tc; cin>>tc;
    for(int i=0; i<tc; i++){
        // cout << "Case #" << i+1 << ": ";
        solve();
    }

    return 0;
}
