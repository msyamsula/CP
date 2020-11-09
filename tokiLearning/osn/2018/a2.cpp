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

string s;
ll k,q;
vl st;

void build(ll p, ll a, ll b, vl arr){
    if (a==b){
        st[p] = arr[a];
        return;
    }

    ll mid = (a+b)/2;
    build(2*p, a, mid, arr);
    build(2*p+1, mid+1, b, arr);
    st[p] = max(st[2*p], st[2*p+1]);
}

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
    return max(rmq(2*p,a,mid,x,y),rmq(2*p+1,mid+1,b,x,y));
}

void solve(){
    cin>>s>>k>>q;
    // cout << "k: " << k << endl;
    // cout << "s: " << s << endl;
    string type;
    for(ll i=0; i<k; i++){
        type+=s;
    }
    // cout << "string: " << s << endl;
    ll n = type.size()+1;
    vl arr(n+1,0);
    arr[0]+=1; arr[n]-=1;
    ll left=0, right=n-1;
    for(ll i=0; i<n-1; i++){
        if (type[i] == 'A'){
            right -=1;
        } else {
            left += 1;
        }
        arr[left]+=1; arr[right+1]-=1;
    }
    vl conf;
    ll sum = 0;
    for(ll i=0; i<arr.size(); i++){
        sum += arr[i];
        conf.push_back(sum);
    }
    conf.pop_back();
    // cout << "conf: ";
    // for(ll num : conf){
    //     cout << num << ' ';
    // }
    // cout << endl;
    st.resize(0); st.assign(4*n, 0);
    // build(1,0,n-1,conf);
    for(ll i=0; i<conf.size(); i++){
        update(1,0,n-1,i,conf[i]);
    }
    for(ll i=0; i<q; i++){
        // get a,b
        ll start, end;
        cin>>start>>end;
        start--; end--;
        cout << rmq(1,0,n-1,start,end) << endl;
        // max query in range a-b
    }
}

int main(){
    string label; cin>>label;
    solve();
    

    return 0;
}
