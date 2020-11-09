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

ll n,m,k;
map<string, set<string>> graph;
map<vs, ll> edges;
map<string, string> p;
ll min_edge;

void backtrack(string u){
    if (p.find(u) == p.end()) return;
    string parent = p[u];
    if (parent == "zonk") return;
    min_edge = min(min_edge, edges[{parent, u}]);
    backtrack(parent);
    edges[{parent, u}] -= min_edge;
}

void solve(){
    cin>>n;
    graph.clear();
    edges.clear();
    for(ll i=0; i<n; i++){
        string a;
        cin>>a;
        // a = tolower(a[0]);
        graph[a].insert("target");
        edges[{a, "target"}]++;
    }

    cin>>m;
    for(ll i=0; i<m; i++){
        string a,b;
        cin>>a>>b;
        // b=tolower(b[0]);
        graph["source"].insert(b);
        edges[{"source", b}]++;
    }

    cin>>k;
    for(ll i=0; i<k; i++){
        string a,b; cin>>a>>b;
        // a = tolower(a[0]);
        // b = tolower(b[0]);
        graph[a].insert(b);
        edges[{a,b}]++;
    }

    cout << "graph" << endl;
    for(pair<string, set<string>> p : graph){
        cout << p.first << ": ";
        for(string s : p.second){
            cout << s << ' ';
        }
        cout << endl;
    }
    cout << endl;

    // cout << "edges: " << endl;
    // for(pair<vs, ll> p : edges){
    //     cout << p.first[0] << ' ' << p.first[1] << ": ";
    //     cout << p.second << endl;
    // }

    ll mf=0;
    // ll idx=0;
    while(1){
        // idx++;
        p.clear();
        p["source"] = "zonk";
        queue<string> q; q.push("source");
        while(!q.empty()){
            string u = q.front(); q.pop();
            // cout << u << endl;
            if (u=="target") break;
            for(string v : graph[u]){
                if (p.find(v) == p.end() && edges[{u,v}] > 0){
                    p[v] = u;
                    q.push(v);
                }
            }
        }

        min_edge = MAXLL;
        backtrack("target");
        // cout << "edges after " << idx << ": " << endl;
        // for(pair<vs, ll> p : edges){
        //     cout << p.first[0] << ' ' << p.first[1] << ": ";
        //     cout << p.second << endl;
        // }

        if (min_edge==MAXLL) break;
        mf += min_edge;
        // if (idx == 5) break;
    }

    cout << m-mf << endl << endl;

}

int main(){
    int tc; cin>>tc;
    for(int i=0; i<tc; i++){
        // cout << "Case #" << i+1 << ": ";
        solve();
    }

    return 0;
}
