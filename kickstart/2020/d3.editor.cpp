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

ll n,a,b;
vvl graph;
vl skipa, skipb;
vl path;

void dfs(ll u, ll type, ll skip){
    if (type == 0) skipa[u]++;
    else skipb[u]++;
    path.push_back(u);
    for(ll v : graph[u]){
        dfs(v, type, skip);
    }

    ll numskip = (type == 0) ? a : b; 
    if (path.size()-1 >= numskip){
        ll prev = path[path.size()-1-numskip];
        if (type==0) skipa[prev]+=skipa[u];
        else skipb[prev]+=skipb[u];
    }
    path.pop_back();
}

void solve(){
    cin>>n>>a>>b;
    graph.resize(0); graph.resize(n);
    for(ll i=0; i<n-1; i++){
        ll u=i+1;
        ll p; cin>>p; p--;
        graph[p].push_back(u);
    }
    skipa.resize(0); skipa.assign(n,0);
    dfs(0,0,a);
    skipb.resize(0); skipb.assign(n,0);
    dfs(0,1,b);

    double sum = 0;
    for(ll i=0; i<n; i++){
        double pa = double(skipa[i])/n;
        double pb = (double)skipb[i]/n;
        double aorb = 1-((1-pa)*(1-pb));
        sum += aorb;
    }

    cout << fixed << setprecision(7) << sum << endl;
}

int main(){
    int tc; cin>>tc;
    for(int i=0; i<tc; i++){
        cout << "Case #" << i+1 << ": ";
        solve();
    }

    return 0;
}
