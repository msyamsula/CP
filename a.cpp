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
ll onePos(ll r, ll c, ll R, ll C){
    return r*C+c;
}

pair<ll, ll> twoPos(ll n, ll R, ll C){
    pair<ll, ll> ans;
    ans.first = n/C;
    ans.second = n%C;

    return ans;
}


void solve(){
    ll n,r,c,sr,sc; scanf("%lld %lld %lld %lld %lld", &n, &r, &c, &sr, &sc);
    // string a; cin>>a;
    sr--; sc--;
    char ss[ll(5e4+5)]; scanf("%s", ss);
    string s(ss);

    unordered_map<ll, ll> top, right, bot, left;

    ll cp = onePos(sr, sc, r, c);

    top[cp] = cp-c;
    bot[cp] = cp+c;
    left[cp] = cp-1;
    right[cp] = cp+1;

    // top[cp] = (sr-1 < 0) ? -1 : onePos(sr-1, sc, r, c);
    // right[cp] = (sc+1 >= c) ? -1 : onePos(sr, sc+1, r, c);
    // bot[cp] = (sr+1 >= r) ? -1 : onePos(sr+1, sc, r, c);
    // left[cp] = (sc-1 < 0) ? -1 : onePos(sr, sc-1, r, c);


    for(ll i=0; i<s.size(); i++){
        char ch = s[i];
        ll pp = cp;

        if (ch == 'N'){
            cp = top[cp];
            top[cp] = cp-c;
            (right.find(cp) == right.end()) ? right[cp] = cp+1 : right[cp] = right[cp];
            bot[cp] = bot[pp];
            (left.find(cp) == left.end()) ? left[cp] = cp-1 : left[cp] = left[cp];
        } else if (ch == 'E'){
            cp = right[cp];
            // (top.find(cp) == top.end()) ? printf("goes here\n") : printf("b\n");
            (top.find(cp) == top.end()) ? top[cp] = cp-c : top[cp] = top[cp];
            // cout << top[cp] << ' ' << cp << ' ' << c << ' ' << cp-c << ' ' << endl;
            right[cp] = cp+1;
            (bot.find(cp) == bot.end()) ? bot[cp] = cp+c : bot[cp] = bot[cp];
            left[cp] = left[pp];
            // cout << 
        } else if (ch == 'S'){
            cp = bot[cp];
            bot[cp] = cp+c;
            top[cp] = top[pp];
            (right.find(cp) == right.end()) ? right[cp] = cp+1 : right[cp] = right[cp];
            (left.find(cp) == left.end()) ? left[cp] = cp-1 : left[cp] = left[cp];
        } else if (ch == 'W') {
            cp = left[cp];
            left[cp] = cp-1;

            right[cp] = right[pp];
            (top.find(cp) == top.end()) ? top[cp] = cp-c : top[cp] = top[cp];
            // if (top.find(27) != top.end()) cout << "top27 " << top[27] << endl;
            (bot.find(cp) == bot.end()) ? bot[cp] = cp+c : bot[cp] = bot[cp];
        }

        bot[top[cp]] = bot[cp];
        left[right[cp]] = left[cp];
        top[bot[cp]] = top[cp];
        right[left[cp]] = right[cp];
        // pair<ll, ll> ans = twoPos(cp, r, c);
        // cout  << pp << "->" << cp << endl;
        // cout << "at: " << ans.first+1 << ' ' << ans.second+1 << endl;
        // cout << "urbl: " << top[cp] << ' ' << right[cp] << ' ' << bot[cp] << ' ' << left[cp] << endl;
    }

    pair<ll, ll> ans = twoPos(cp, r, c); r++; c++;
    printf("%lld %lld\n", ans.first+1, ans.second+1);

    // cout << n << r << c << sr << sc << a << endl;
    // printf("%s\n", a.c_str());
    // cout << "hello" << endl;
    // printf("%s\n", s.c_str());
}


int main(){
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // int tc; cin>>tc;
    int tc; scanf("%lld", &tc);
    // printf("%lld\n", tc);
    for(ll i=0; i<tc; i++){
        printf("Case #%lld: ", i+1);
        solve();
    }
    return 0;
}