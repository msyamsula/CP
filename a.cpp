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
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // int tc; cin>>tc;
    // int tc; scanf("%lld", &tc);
    // for(ll i=0; i<tc; i++){
    //     // printf("Case #%lld: ", i+1);
        solve();
    // }
    return 0;
}