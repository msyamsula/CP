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

vl st1;
vl st2;
// vl arr;

void update1(ll p, ll a, ll b, ll idx, ll val){
    // cout << p << endl;
    if (b<idx || a>idx) return;
    else if (idx<=a && b<=idx){
        st1[p] = val;
        if (idx%2!=0) st1[p] = -st1[p];
        return;
    }

    ll mid = (a+b)/2;
    update1(2*p, a, mid, idx, val);
    update1(2*p+1, mid+1, b, idx, val);
    st1[p] = st1[2*p]+st1[2*p+1];
}

ll rmq1(ll p, ll a, ll b, ll x, ll y){
    if (b<x || a>y) return 0;
    else if (x<=a && b<=y) return st1[p];

    ll mid = (a+b)/2;
    ll left = rmq1(2*p, a, mid, x, y);
    ll right = rmq1(2*p+1, mid+1, b, x, y);

    return right+left;
}

void update2(ll p, ll a, ll b, ll idx, ll val){
    // cout << p << endl;
    if (b<idx || a>idx) return;
    else if (idx<=a && b<=idx){
        st2[p] = val*(idx+1);
        if (idx%2!=0) st2[p] = -st2[p];
        return;
    }

    ll mid = (a+b)/2;
    update2(2*p, a, mid, idx, val);
    update2(2*p+1, mid+1, b, idx, val);
    st2[p] = st2[2*p]+st2[2*p+1];
}

ll rmq2(ll p, ll a, ll b, ll x, ll y){
    if (b<x || a>y) return 0;
    else if (x<=a && b<=y) return st2[p];

    ll mid = (a+b)/2;
    ll left = rmq2(2*p, a, mid, x, y);
    ll right = rmq2(2*p+1, mid+1, b, x, y);

    return right+left;
}

void solve(){
    ll n,q; cin>>n>>q;
    st1.resize(0); st1.assign(4*n, 0);
    st2.resize(0); st2.assign(4*n, 0);
    for(ll i=0; i<n; i++){
        // cout << i << endl;
        ll ntemp; cin>>ntemp;
        // arr.push_back(ntemp);
        update1(1,0,n-1,i,ntemp);
        update2(1,0,n-1,i,ntemp);
    }
    // for(int num : st1){
    //     cout << num << ' ';
    // }
    // cout << endl;

    // for(int num : st2){
    //     cout << num << ' ';
    // }
    // cout << endl;


    ll tot = 0;
    for(ll i=0; i<q; i++){
        char c; cin>>c;
        if (c=='U'){
            ll idx,val; cin>>idx>>val; idx--;
            update1(1,0,n-1,idx,val);
            update2(1,0,n-1,idx,val);
        } else if (c=='Q'){
            ll x,y; cin>>x>>y; x--; y--;
            ll big = rmq2(1,0,n-1,0,y);
            ll small = (x-1 < 0) ? 0 : rmq2(1,0,n-1,0,x-1);
            ll intermediete = big-small;
            ll aux = rmq1(1,0,n-1,x,y)*x;
            ll atemp = intermediete - aux;
            atemp = (x%2==0) ? atemp : -atemp;
            tot += atemp;
            // cout << big << endl;
            // cout << small << endl;
            // cout << tot << endl;
            // cout << aux << endl;
        }
    }

    cout << tot << endl;
}

int main(){
    int tc; cin>>tc;
    for(int i=0; i<tc; i++){
        cout << "Case #" << i+1 << ": ";
        solve();
    }

    return 0;
}
