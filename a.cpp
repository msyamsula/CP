// #include<bits/stdc++.h>
#include<iostream>
#include<utility>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
#include<bitset>
#include<cmath>
#include<stack>
#include<queue>
#include<list>
#include<cstring>
#include<string.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<ll> vl;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<vl> vvl;
typedef vector<vvl> vvvl;
typedef vector<vs> vvs;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vs> vvs;
#define accuracy (10e-6)
#define INF (1ll<<62)
#define PI 3.14159265358979323846

void show(vs arr){
    for(string num : arr){
        cout << num << '\n';
    }
    cout << endl;
}


void show(vl arr){
    for(ll i=0; i<arr.size(); i++){
        if (i!=0) cout << ' ';
        cout << arr[i];
    }
    cout << endl;
}

void show(vvl mat){
    for(vl arr : mat){
        show(arr);
    }
    cout << endl;
}

void show(set<ll> s){
    for(ll num : s){
        cout << num << ' ';
    }
    cout << endl;
}

void show(map<pair<ll, ll>, ll> mp){
    for(pair<pair<ll, ll>, ll> p : mp){
        cout << p.first.first << ' ' << p.first.second << ": " << p.second << endl;
    }
    cout << endl;
}

void inputArray(vl &v){
    ll n = v.size();
    for(ll i=0; i<n; i++){
        scanf("%lld", &v[i]);
    }
}

void inputArray2(ll *ptr, ll n){
    for(ll i=0; i<n; i++){
        cin>>*(ptr+i);
    }
}

void dfs(vvl &g, map<pair<ll, ll>, ll> &e, vvl &t, vl &visited, ll u, pair<ll, ll> &state, vector<pair<ll, ll>> &st){
    visited[u] = 1;

    bitset<10> tmpb(state.first);
    bitset<10> cs;
    for(ll type : t[u]){
        cs[type] = 1;
    }
    bitset<10> ns; ns = cs | tmpb;
    state.first = ns.to_ullong();
    // printf("\nvisited %lld", u);
    cout << endl << "visited " << u << ' ' << bitset<10>(state.first);

    if (u == g.size()-1){
        // st.insert(state);
        st.push_back(state);
        cout << endl << bitset<10>(state.first);
        visited[u] = 0;
        state.first = tmpb.to_ullong();
        return;
    }

    for(ll v : g[u]){
        if (visited[v] == 1) continue;
        state.second += e[{u,v}];
        dfs(g,e,t,visited, v, state, st);
        state.second -= e[{u,v}];
    }

    visited[u] = 0;
    state.first = tmpb.to_ullong();
}

void solve(){
    ll n,m,k; scanf("%lld %lld %lld", &n, &m, &k);
    vvl t; t.resize(n);
    for(ll i=0; i<n; i++){
        ll x; scanf("%lld", &x);
        for(ll j=0; j<x; j++){
            ll type; scanf("%lld", &type); type--;
            t[i].push_back(type);
        }
    }

    vvl g; g.resize(n);
    map<pair<ll,ll>, ll> e;
    for(ll i=0; i<m; i++){
        ll u,v,w; scanf("%lld %lld %lld", &u, &v,&w), u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
        e[{u,v}] = w;
        e[{v,u}] = w;
    }

    vector<pair<ll, ll>> st;
    pair<ll, ll> state;
    vl visited; visited.assign(n, 0);

    dfs(g,e,t,visited,0,state,st);

    for(pair<ll,ll> p : st){
        cout << bitset<10>(p.first) << ' ' << p.second << endl;
    }

    ll ans = INF;
    for(ll i=0; i<st.size(); i++){

        for(ll j=i; j<st.size(); j++){
            bitset<10> a(st[i].first), b(st[j].first);
            bitset<10> c = a | b;
            if (c.to_ullong() == (1ll<<k)-1){
                ans = min(ans, max(st[i].second, st[j].second));
            }
        }
    }

    printf("%lld\n", ans);
class ST{
private:
    vl parr;
    vl stSum, stMin;
    vl lazy;
    ll n;

    void push(ll p, ll i, ll j){
        if (lazy[p] == 0) return;

        // printf("\n lazy[%lld]: %lld", p, lazy[p]);
        stSum[p] += (j-i+1)*lazy[p];
        stMin[p] += lazy[p];
        ll left = 2*p, right = 2*p + 1;

        if (i != j){
            lazy[left] += lazy[p];
            lazy[right] += lazy[p];
        }

        lazy[p] = 0;
        // printf("\n pushing %lld, %lld", p, stSum[p]);
    }

    void build(ll p, ll i, ll j){
        if (i==j){
            stSum[p] = stMin[p] = parr[i];
            return;
        }

        ll left = 2*p, right = 2*p+1;
        ll mid = (i+j)/2;
        build(left, i, mid);
        build(right, mid+1, j);

        stSum[p] = stSum[left] + stSum[right];
        stMin[p] = min(stMin[left],stMin[right]);

        // printf("\n after build %lld, result: %lld", p, stSum[p]);
    }

    ll rsq(ll p, ll i, ll j, ll x, ll y){
        push(p, i, j);
        if (j<x || i>y) return 0;
        if (x<=i && j<=y) return stSum[p];

        ll left = 2*p, right = 2*p + 1, mid = (i+j)/2;
        return rsq(left, i, mid, x, y) + rsq(right, mid+1, j, x, y);
    }

    ll rmq(ll p, ll i, ll j, ll x, ll y){
        push(p, i, j);
        if (j<x || i>y) return INF;
        if (x<=i && j<=y) return stMin[p];

        ll left = 2*p, right = 2*p + 1, mid = (i+j)/2;
        return min(rmq(left, i, mid, x, y), rmq(right, mid+1, j, x, y));
    }

    void update(ll p, ll i, ll j, ll x, ll y, ll val){
        push(p, i, j);
        if (j<x || i>y) return;
        if (x<=i && j<=y){
            lazy[p] += val;
            push(p, i, j);
            return;
        }

        ll left = 2*p, right = 2*p + 1, mid = (i+j)/2;
        update(left, i, mid, x, y, val);
        update(right, mid+1, j, x, y, val);

        stSum[p] = stSum[left] + stSum[right];
        stMin[p] = min(stMin[left], stMin[right]);
    }
public:
    ST(vl arr){
        parr = arr;
        n = arr.size();
        stSum.resize(4*(n), 0);
        stMin = stSum;
        lazy = stMin;
        build(1, 0, n-1);
    }

    ll rmq(ll x, ll y){
        return rmq(1, 0, n-1, x, y);
    }

    ll rsq(ll x, ll y){
        return rsq(1, 0, n-1, x, y);
    }

    void update(ll x, ll y, ll val){
        return update(1, 0, n-1, x, y, val);
    }

    void showSTsum(){
        printf("\n");
        for(ll i=0; i<stSum.size(); i++){
            printf(" %lld", stSum[i]);
        }
    }

};

void solve(){
    ll n; scanf("%lld\n", &n);

    vl arr(n,0);
    vl ps1 = arr, ps2 = arr;

    for(ll i=0; i<n; i++){
        scanf("%lld", &arr[i]);
        ps1[i] = ( (i-1<0) ? 0 : ps1[i-1])+arr[i];
        ps2[i] = ( (i-1<0) ? 0 : ps2[i-1]) + ps1[i];
    }

    // printf("\n");
    // for(ll i=0; i<ps1.size(); i++){
    //     printf(" %lld", ps1[i]);
    // }

    ST mst = ST(ps1);

    ll i=0, j=0;
    vvl happyRange;
    while(i<n && j<n){
        while(arr[i]<0) i++;

        j=i;

        while(j<n && ps1[j]- ( (i-1 < 0) ? 0 : ps1[i-1]) >= 0) j++;

        happyRange.push_back({i,j-1});
        i=j;
    }

    ll ans = 0;
    for(ll i=0; i<happyRange.size(); i++){
        // printf("\n %lld %lld", happyRange[i][0], happyRange[i][1]);
        ll ii = happyRange[i][0], jj = happyRange[i][1];
        ans += ps2[jj] - ( (ii-1<0) ? 0 : ps2[ii-1]);
        ans -= (jj-ii+1)*( (ii-1<0) ? 0 : ps1[ii-1]);
        // ans += mst.rsq(ii, jj) - (jj-ii+1)*(ps1[ii-1]);

        for(ll k=ii+1; k<=jj; k++){
            ll prevPs = (k-1<0) ? 0 : ps1[k-1];
            // printf("\n prevPs: %lld", prevPs);

            mst.update(k, jj, -prevPs);

            if (mst.rmq(k, jj) < 0){
            } else {
                ll add = ps2[jj] - ps2[k-1];
                add -= (jj-k+1)*( (k-1<0) ? 0 : ps1[k-1]);
                ans += add;
                // printf("\n%lld %lld: happy, add: %lld, rmq: %lld", k, jj, add, mst.rmq(k, jj));
            }

            mst.update(k, jj, prevPs);
        }
    }

    // printf("\n");
    printf("%lld\n", ans);

    // mst.showSTsum();

    // printf("\n%lld", mst.rmq(0,2)); // -1
    // printf("\n%lld", mst.rmq(0,4)); // -1
    // printf("\n%lld", mst.rmq(0,3)); // -1
    // printf("\n%lld", mst.rmq(1,2)); // -1
    // printf("\n%lld", mst.rmq(3,4)); // 0
    // mst.update(1,3,2);
    // printf("\n%lld", mst.rsq(1,3)); // 7 x
    // printf("\n%lld", mst.rmq(1,3)); // 1
    // printf("\n%lld", mst.rmq(1,1)); // 1
    // printf("\n%lld", mst.rmq(2,2)); // 4
    // printf("\n%lld", mst.rmq(3,3)); // 2
    // printf("\n%lld", mst.rsq(1,3)); // 2




}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // int tc; cin>>tc;
    int tc; scanf("%lld", &tc);
    for(ll i=0; i<tc; i++){
        printf("Case #%lld: ", i+1);
        solve();
    }
    return 0;
}