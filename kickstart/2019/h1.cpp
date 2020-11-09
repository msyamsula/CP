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

ll N;
vl st;
ll max_len = 100000;

void update(ll p, ll a, ll b, ll idx, ll val){
    if (b<idx || a>idx) return;
    if (a==b && a==idx){
        st[p] += val;
        return;
    }

    ll mid = (a+b)/2;
    update(2*p, a, mid, idx, val); update(2*p+1, mid+1, b, idx, val);
    st[p] = st[2*p]+st[2*p+1];
}

ll rsq(ll p, ll a, ll b, ll x, ll y){
    if (b<x || a>y) return 0;
    if (x<=a && b<=y) return st[p];

    ll mid = (a+b)/2;
    ll left = rsq(2*p, a, mid, x, y), right = rsq(2*p+1, mid+1, b, x, y);
    return left + right;
}

void solve(){
    cin>>N;
    st.resize(0);
    st.assign(4*(max_len+1), 0);
    ll h_index = 0;
    for(ll i=0; i<N; i++){
        ll temp; cin>>temp;
        update(1, 0, max_len, temp, 1);
        ll cnt = rsq(1, 0, max_len, h_index+1, max_len);
        ll new_h = min(i+1, cnt);
        // cout << cnt << ' ' << i+1 << ' ' << h_index << ' ' << new_h << endl;
        h_index = max(h_index, new_h);
        if (i!=0) cout << ' ';
        cout << h_index;
    }
    cout << endl;
}

int main(){
    int tc; cin>>tc;
    for(int i=0; i<tc; i++){
        cout << "Case #" << i+1 << ": ";
        solve();
    }

    return 0;
}
