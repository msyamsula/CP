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

// ll n,m;
// vl st;
// string s;

// void update(ll p, ll a, ll b, ll idx, ll val){
//     if (b<idx || a>idx) return;
//     if (idx<=a && b<=idx){
//         st[p] = val;
//         return;
//     }

//     ll mid = (a+b)/2;
//     update(2*p, a, mid, idx, val);
//     update(2*p+1, mid+1, b, idx, val);
//     st[p] = st[2*p] + st[2*p+1];
// }

// ll rsq(ll p, ll a, ll b, ll x, ll y){
//     if (b<x || a>y) return 0;
//     if (x<=a && b<=y) return st[p];

//     ll mid = (a+b)/2;
//     return rsq(2*p, a, mid, x, y) + rsq(2*p+1, mid+1, b, x, y);
// }

// void solve(){
//     cin>>s;
//     n = s.size();
//     cin>>m;
//     st.resize(0); st.assign(4*n, 0);
//     for(ll i=0; i<n-1; i++){
//         if (s[i]==s[i+1]){
//             update(1, 0, n-1, i, 1);
//         }
//     }

//     for(ll i=0; i<m; i++){
//         ll x,y; cin>>x>>y;
//         x--; y--;
//         cout << rsq(1,0,n-1,x,y-1) << endl;
//     }
// }

ll n,m;
string s;
vl ps;

void solve(){
    cin>>s;
    n = s.size();
    ps.resize(0); ps.assign(n+1, 0);
    for(ll i=0; i<n; i++){
        ll val = 0;
        if (i+1 < n){
            if (s[i] == s[i+1]) val = 1;
        }
        ps[i+1] = ps[i] + val;
    }

    cin>>m;
    for(ll i=0; i<m; i++){
        ll a,b; cin>>a>>b;
        a--; b--;
        cout << ps[b]-ps[a] << endl;
    }
}


int main(){
    solve();
    // int tc; cin>>tc;
    // for(int i=0; i<tc; i++){
    //     cout << "Case #" << i+1 << ": ";
    //     solve();
    // }

    return 0;
}
