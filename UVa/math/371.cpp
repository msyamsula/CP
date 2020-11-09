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

unordered_map<ll, ll> cl;
vvl st;
ll len_max = 1000000;

void update(ll p, ll a, ll b, ll idx, ll val){
    if (idx<=a && b<=idx){
        st[p][0] = val;
        st[p][1] = idx;
        return;
    }

    if (b<idx || a>idx) return;

    ll mid = (a+b)/2;
    update(2*p, a, mid, idx, val); update(2*p+1, mid+1, b, idx, val);
    if (st[2*p][0] >= st[2*p+1][0]){
        st[p] = st[2*p];
    } else {
        st[p] = st[2*p+1];
    }
}

void update(ll idx, ll val){
    update(1, 0, len_max, idx, val);
}

vl rmq(ll p, ll a, ll b, ll x, ll y){
    if (b<x || a>y) return {-MAXLL,-1};
    if (x<=a && b<=y) return st[p];
    ll mid = (a+b)/2;
    vl left = rmq(2*p, a, mid, x, y), right = rmq(2*p+1, mid+1, b, x, y);
    if (left[0] >= right[0]){
        return left;
    }
    return right;
}

vl rmq(ll x, ll y){
    return rmq(1, 0, len_max, x, y);
}

ll cycle_length(ll n){
    if (cl.find(n) != cl.end()) return cl.at(n);

    if (n%2 == 0) return cl[n] = 1 + cycle_length(n/2);

    return cl[n] = 1 + cycle_length(3*n+1);
}

void solve(){

}

int main(){
    
    st.assign(4*(len_max+1), {0,-1});
    cl[1] = 1;
    for(ll i=1; i<=len_max; i++){
        update(i, cycle_length(i));
    }
    update(1, 4);
    ll a, b;
    while(cin>>a>>b){
        if (!a && !b) break;
        vl arr = {a,b};
        sort(arr.begin(), arr.end());
        vl ans = rmq(arr[0],arr[1]);
        cout << "Between " << arr[0] << " and " << arr[1] << ", " << ans[1] << " generates the longest sequence of " << ans[0]-1 << " values." << endl;
        // cout << a << ' ' << b << ' ' << rmq(arr[0],arr[1]) << endl;
    }
    

    return 0;
}