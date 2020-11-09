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

ll n;
vl st;

void update(ll p, ll a, ll b, ll idx, ll val){
    if (b<idx || a>idx) return;
    if (idx<=a && b<=idx){
        st[p] = val;
        return;
    }
    
    ll mid = (a+b)/2;
    update(2*p, a, mid, idx, val);
    update(2*p+1, mid+1, b, idx, val);
    st[p] = max(st[2*p], st[2*p+1]);
}

ll rsq(ll p, ll a, ll b, ll x, ll y){
    if (b<x || a>y) return -MAXLL;
    if (x<=a && b<=y) return st[p];

    ll mid = (a+b)/2;
    return max(rsq(2*p, a, mid, x, y), rsq(2*p+1, mid+1, b, x, y));
}

void solve(){
    cin>>n;
    ll sum_w = 0;
    vl height, width;
    st.resize(0); st.assign(4*n, 0);
    for(ll i=0; i<n; i++){
        ll w,h; cin>>w>>h;
        sum_w+=w;
        height.push_back(h);
        width.push_back(w);
        update(1,0,n-1,i,h);
    }

    for(ll i=0; i<n; i++){
        ll w = sum_w - width[i];
        ll h;
        if (i==0) h = rsq(1,0,n-1,1,n-1);
        else if (i==n-1) h = rsq(1,0,n-1,0,n-2);
        else h = max(rsq(1,0,n-1,0,i-1), rsq(1,0,n-1,i+1,n-1));

        ll area = w*h;
        if (i!=0) cout <<' ';
        cout << area;
    }
    cout << endl;
}

int main(){
    solve();

    return 0;
}
