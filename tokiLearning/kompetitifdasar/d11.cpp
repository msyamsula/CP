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


vi ufd;
vector<iii> edges;

int parent(int u){
    if(ufd[u]<0) return u;
    return parent(ufd[u]);
}

void join(int u, int v){
    int pu=parent(u), pv=parent(v);
    if (pu==pv) return;

    if (ufd[pu] <= ufd[pv]){
        ufd[pu] += ufd[pv];
        ufd[pv] = pu;
    } else {
        ufd[pv] += ufd[pu];
        ufd[pu] = pv;
    }
}

bool comp(iii a, iii b){
    if (a.second != b.second){
        return a.second<b.second;
    } else if (a.first.first != b.first.first){
        return a.first.first<b.first.first;
    }

    return a.first.second<b.first.second;
}

int main(){
    int n; cin>>n;
    ufd.assign(n,-1);    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            int u=i,v=j;
            int w; cin>>w;
            if (w>0) edges.push_back({{u,v},w});
            // cout << w << ' ';
        }

        // cout << endl;
    }
    sort(edges.begin(), edges.end(), comp);

    // for(iii a : edges){
    //     cout << a.first.first << ' ' << a.first.second << ' ' << a.second << endl;
    // }

    ll minim = 0;
    for(int i=0; i<edges.size(); i++){
        ll u = edges[i].first.first, v = edges[i].first.second, w=edges[i].second;
        int pu = parent(u), pv = parent(v);
        if (pu == pv) continue;
        minim += w;
        join(u,v);
    }

    cout << minim << endl;
    return 0;
}
