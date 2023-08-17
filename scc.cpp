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

vvl transposeGraph(vvl &graph){
    ll n = graph.size();
    vvl gt; gt.resize(n);
    for(ll u=0; u<n; u++){
        for(ll v : graph[u]){
            gt[v].push_back(u);
        }
    }

    return gt;
}

void sccDFS(vvl &graph, vl &visited, ll u, stack<ll> &st, ll x, vl &air){
    if (air[u] < x) return;

    visited[u] = 1;
    for(ll v : graph[u]){
        if (visited[v] == 1) continue;
        if (air[v] < x) continue;
        sccDFS(graph, visited, v, st, x, air);
    }

    st.push(u);
}

void secondDFS(vvl &graph, vl &visited, ll u, vl &path, ll x, vl &air){
    if (air[u] < x) return;

    visited[u] = 1;
    path.push_back(u);
    for(ll v : graph[u]){
        if (visited[v] == 1) continue;
        if (air[v] < x) continue;
        secondDFS(graph, visited, v, path, x, air);
    }
}

vvl scc(vvl graph, ll x, vl &air){
    vvl gt = transposeGraph(graph);
    // show(gt);

    ll n = graph.size();
    stack<ll> st;
    vl visited; visited.assign(n, 0);
    for(ll i=0; i<n; i++){
        if (visited[i] == 1) continue;
        if (air[i] < x) continue;
        sccDFS(graph, visited, i, st, x, air);
    }


    visited.resize(0); visited.assign(n, 0);

    vl path;
    vvl sccGroup;

    while(!st.empty()){
        ll u = st.top(); st.pop();
        if (visited[u] == 1) continue;
        if (air[u] < x) continue;

        // printf(" %lld", u);
        path.resize(0);
        secondDFS(gt, visited, u, path, x, air);
        sccGroup.push_back(path);
        // show(visited);
        // show(path);
    }

    return sccGroup;
}

ll maxSccGroup(vvl graph, ll x, vl &air){
    vvl sg = scc(graph, x, air);
    ll ans = 0;
    for(ll i=0; i<sg.size(); i++){
        ans = max(ans, ll(sg[i].size()));
    }

    return ans;
}

void solve(){
    // printf("\nHello World");
    ll n,m,k; scanf("%lld %lld %lld", &n, &m, &k);
    vvl graph; graph.resize(n);
    vl air; air.assign(n, 0);
    for(ll i=0; i<n; i++){
        scanf("%lld", &air[i]);
    }


    for(ll i=0; i<m; i++){
        ll u,v; scanf("%lld %lld", &u, &v); u--; v--;
        graph[u].push_back(v);
    }

    ll left = 0, right = 1e9;
    ll ans;
    while(left<=right){
        ll mid = (left+right)/2;
        ll msc = maxSccGroup(graph, mid, air);
        printf("\n %lld %lld, %lld: %lld %lld", left, right, mid, msc, k);

        bool y = (msc < k);

        if (y) right = mid;
        else left = mid + 1;

        if (left > 1e9){
            ans = left; break;
        }

        if (left == right){
            ans = left; break;
        }
    }

    ans--;

    printf("%lld\n", ans);
    vvl sccGroup = scc(graph, 3, air);

    for(vl v : sccGroup){
        printf("\n");
        for(ll u : v){
            printf(" %lld", u);
        }
    }
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