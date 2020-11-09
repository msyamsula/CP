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

vi ufd;
vector<pair<ii, int>> edges;

bool comp(pair<ii, int> a, pair<ii, int> b){
    if (a.second != b.second){
        return a.second < b.second;
    } else if (a.first.first != b.first.first){
        return a.first.first < b.first.first;
    }

    return a.first.second < b.first.second;
}

int parent(int a){
    if(ufd[a] < 0) return a;
    return parent(ufd[a]);
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
    ufd.resize(0); ufd.assign(m, -1); edges.resize(0);
    long long init = 0;
    for(int i=0; i<n; i++){
        int u,v,w; cin>>u>>v>>w;
        edges.push_back({{u,v},w});
        // edges.push_back({{v,u},w});
        init += w;
    }

    sort(edges.begin(), edges.end(), comp);

    long long minim = 0;
    for(pair<ii, int> temp : edges){
        int u = temp.first.first, v = temp.first.second, w = temp.second;
        int pu = parent(u), pv = parent(v);
        // cout << u << ' ' << v << ' ' << w << endl;
        if (pu == pv) continue;
        minim += w;
        join(u,v);
    }

    cout << init - minim << endl;
}

int main(){
    // int tc; cin>>tc;
    int m, n;
    while(cin>>m>>n){
        // cout << "Case #" << i+1 << ": ";
        if (!m && !n) break;
        solve(m,n);
    }

    return 0;
}