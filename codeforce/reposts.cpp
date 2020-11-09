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
map<string, vs> graph;

void solve(){
    cin>>n;
    graph.clear();
    for(ll i=0; i<n; i++){
        string v,r,u; cin>>v>>r>>u;
        string uc = "";
        for(char c : u){
            uc+=tolower(c);
        }

        string vc = "";
        for(char c : v){
            vc+=tolower(c);
        }
        graph[uc].push_back(vc);
    }

    // cout << "graph: " << endl;
    // for(pair<string, vs> p : graph){
    //     cout << p.first <<": ";
    //     for(string s : p.second){
    //         cout << s << ' ';
    //     }
    //     cout << endl;
    // }

    map<string, bool> visited;
    map<string, ll> dis;
    queue<string> q;
    q.push("polycarp");
    visited["polycarp"]=1;
    dis["polycarp"]=1;
    ll max_len = 0;
    while(!q.empty()){
        string u = q.front(); q.pop();
        // cout << u << endl;
        for(string v : graph[u]){
            if (visited[v] == 1) continue;
            visited[v] = 1;
            dis[v] = dis[u]+1;
            max_len = max(max_len, dis[v]);
            q.push(v);
        }
    }

    cout << max_len << endl;
}

int main(){
    solve();
    // int tc; cin>>tc;
    // for(int i=0; i<tc; i++){
    //     cout << "Case #" << i+1 << ": ";
    // }

    return 0;
}
