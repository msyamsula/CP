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
vl problems;

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
ll rmq(ll p, ll a, ll b, ll x, ll y){
    if (b<x || a>y) return -MAXLL;
    if (x<=a && b<=y) return st[p];

    ll mid = (a+b)/2;
    ll left = rmq(2*p, a, mid, x, y);
    ll right = rmq(2*p+1, mid+1, b, x, y);
    return max(left, right);
}

void solve(){
    cin>>n;
    problems.resize(0);
    for(ll i=0; i<n; i++){
        ll temp; cin>>temp;
        problems.push_back(temp);
    }
    st.resize(0); st.assign(4*n, 0);
    update(1,0,n-1,n-1,1);
    for(ll i=n-2; i>=0; i--){
        ll num = problems[i];
        auto it = upper_bound(problems.begin(), problems.end(), 2*num);
        it--;
        ll end_idx = distance(problems.begin(), it);
        ll max_choice = rmq(1,0,n-1,i,end_idx);
        update(1,0,n-1,i,1+max_choice);
    }

    cout << rmq(1,0,n-1,0,n-1) << endl;
}

int main(){
    solve();
    // int tc; cin>>tc;
    // for(int i=0; i<tc; i++){
    //     cout << "Case #" << i+1 << ": ";
    // }

    return 0;
}
