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
ll n;
vvl graph;
// vl visited;
ll ans;
vl dag;

void dfs(ll u, ll d){
    if (d==2){
        ans++;
        // cout << "dag: ";
        // for(ll num : dag){
        //     cout << num << ' ';
        // }
        // cout << endl;
        return;
    }

    for(ll v : graph[u]){
        dag.push_back(v);
        dfs(v, d+1);
        dag.pop_back();
    }
}

void solve(){
    cin>>s;
    // cout << "s: " << s << endl;
    n = s.size();
    graph.resize(0); graph.resize(n);
    vl q,a;
    for(ll i=0; i<n; i++){
        if (s[i] == 'Q'){
            for(ll u : a){
                graph[u].push_back(i);
            }
            q.push_back(i);
        } else if (s[i] == 'A') {
            for(ll u : q){
                graph[u].push_back(i);
            }
            a.push_back(i);
        }
    }

    // cout << "q: ";
    // for(ll num : q){
    //     cout << num << ' ';
    // }
    // cout << endl;

    // cout << "a: ";
    // for(ll num : a){
    //     cout << num << ' ';
    // }
    // cout << endl;

    // cout << "graph: " << endl;
    // ll node = 0;
    // for(vl arr : graph){
    //     cout << node << ": ";
    //     for(ll num : arr){
    //         cout << num << ' ';
    //     }
    //     cout << endl;
    //     node++;
    // }

    ans = 0;
    // visited.resize(0); visited.assign(n, 0);
    for(ll u : q){
        dag.push_back(u);
        dfs(u,0);
        dag.pop_back();
    }

    cout << ans << endl;
}

int main(){
    solve();

    return 0;
}
