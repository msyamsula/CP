#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<long long> vl;
typedef vector<vl> vvl;
typedef vector<string> vs;
typedef vector<vs> vvs;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
#define MAXLL (1ll<<60)
#define MAXI (1<<30)

map<string, int> mem;
vector<iii> edges;
vi par;

int parent(int a){
    if (par[a] < 0) return a;
    return parent(par[a]);
}

void join(int a, int b){
    int pa = parent(a), pb = parent(b);

    if (pa == pb) return;

    if (par[pa] <= par[pb]){
        par[pa] += par[pb];
        par[pb] = pa;
    } else {
        par[pb] += par[pa];
        par[pa] = pb;
    }
}

bool comp(iii a, iii b){
    if (a.first != b.first){
        return (a.first < b.first);
    } else if (a.second.first != b.second.first){
        return (a.second.first < b.second.first);
    }

    return (a.second.second < b.second.second);
}

void solve(){
    int n,e; cin>>n>>e;
    mem.clear();
    edges.resize(0);
    par.resize(0); par.assign(n, -1);
    for(int i=0; i<e; i++){
        string a,b; cin>>a>>b;
        int w; cin>>w;
        int u,v;
        if (mem.find(a) == mem.end()){
            mem[a] = mem.size();
        }
        u = mem.at(a);
        if (mem.find(b) == mem.end()){
            mem[b] = mem.size();
        }
        v = mem.at(b);
        edges.push_back({w,{u,v}});
        edges.push_back({w,{v,u}});
    }

    sort(edges.begin(), edges.end(), comp);
    long long min = 0ll;
    for(iii temp : edges){
        long long w = temp.first;
        int u = temp.second.first, v = temp.second.second;
        int pu = parent(u), pv = parent(v);
        if (pu == pv) continue;
        join(u,v);
        min += w;
    }


    cout << min << endl;
}

int main(){
    int tc; cin>>tc;
    for(int i=0; i<tc; i++){
        if (i!=0) cout << endl;
        // cout << "Case #" << i+1 << ": ";
        solve();
    }

    return 0;
}