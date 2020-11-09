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
#define MAXLL (1ll<<60)
#define MAXI (1<<30)

map<string, int> mem;
vector<pair<ii, int>> edges;
vi ufd;

bool comp(pair<ii, int> a , pair<ii, int> b){
    if (a.second != b.second){
        return a.second < b.second;
    } else if (a.first.first != b.first.first){
        return a.first.first < b.first.first;
    }

    return a.first.second < b.first.second;
}

int parent(int u){
    if (ufd[u] < 0) return u;
    return parent(ufd[u]);
}

void join(int u, int v){
    int pu = parent(u), pv = parent(v);
    if (pu == pv) return;

    if (ufd[pu] <= ufd[pv]){
        ufd[pu] += ufd[pv];
        ufd[pv] = pu;
    } else {
        ufd[pv] += ufd[pu];
        ufd[pu] = pv;
    }
}

void solve(int m, int n){
    mem.clear(); edges.resize(0); ufd.resize(0); ufd.assign(m, -1);
    for(int i=0; i<m; i++){
        string name; cin>>name;
        mem[name] = mem.size();
    }

    for(int i=0; i<n; i++){
        string nameu, namev; cin>>nameu>>namev;
        int u = mem.at(nameu), v = mem.at(namev);
        int w; cin>>w;
        edges.push_back({{u,v}, w});
        edges.push_back({{v,u}, w});
    }

    string dum; cin>>dum;

    sort(edges.begin(), edges.end(), comp);

    long long minim = 0;
    for(pair<ii, int> temp : edges){
        int u = temp.first.first, v = temp.first.second, w = temp.second;
        int pu = parent(u), pv = parent(v);
        if (pu == pv) continue;
        minim += w;
        join(u,v);
    }

    int sectionCount = 0;
    for(int temp : ufd){
        if (temp < 0) sectionCount++;
    }

    if (sectionCount == 1){
        cout << minim << endl;
        return;
    }

    cout << "Impossible" << endl;
}

int main(){
    int m, n;
    while(cin>>m>>n){
        // cout << "Case #" << i+1 << ": ";
        if (!m && !n) break;
        solve(m,n);
    }

    return 0;
}