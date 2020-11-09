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

ll N, n;
vvl graph;
vl visited;
vvl ans;
vl cur_path;

void dfs(ll u, ll d){
    // cout << u << endl;
    if (d == n){
        // for(ll num : cur_path){
        //     cout << num << ' ';
        // }
        // cout << endl;
        cur_path.push_back(u+1);
        ans.push_back(cur_path);
        cur_path.pop_back();
        return;
    }

    // visited[u]=1;
    for(ll v : graph[u]){
        if (visited[v] == 0){
            visited[v] = 1;
            cur_path.push_back(v+1);
            dfs(v, d+1);
            visited[v] = 0;
            cur_path.pop_back();
        }
    }
}

void solve(){
    // cout << N << endl;
    visited.resize(0); visited.assign(N, 0);
    visited[0]=1;
    graph.resize(0); graph.resize(N);
    for(ll i=0; i<N; i++){
        for(ll j=0; j<N; j++){
            ll temp; cin>>temp;
            if (temp){
                // cout << "tes" << endl;
                ll u = i, v=j;
                graph[u].push_back(v);
            }
        }
    }

    ans.resize(0);
    cur_path.resize(0); cur_path.push_back(1);
    dfs(0, 0);

    if (ans.size() == 0){
        cout << "no walk of length "<< n << endl;
        return;
    }

    sort(ans.begin(), ans.end());

    for(ll a=0; a<ans.size(); a++){
        cout << '(';
        for(ll i=0; i<=n; i++){
            if (i!=0) cout << ',';
            cout << ans[a][i];
        }
        cout << ')' << endl;
    }
}

int main(){
    ll i = 0;
    ll dummy;
    while(1){
        if (i!=0){
            cin>>dummy;
        }
        if(cin>>N>>n){
            if (i!=0) cout << endl;
            solve();
        }
        else break;
        i++;
    }

    return 0;
}
