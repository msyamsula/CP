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

int parent(int u){
    if(ufd[u] < 0) return u;
    return parent(ufd[u]);
}

void join(int u, int v){
    int pu = parent(u), pv = parent(v);
    if (pu == pv) return;

    if (ufd[pu] < ufd[pv]){
        ufd[pu] += ufd[pv];
        ufd[pv] = pu;
    } else {
        ufd[pv] += ufd[pu];
        ufd[pu] = pv;
    }
}

int main(){
    int n,q; cin>>n>>q;
    ufd.resize(0); ufd.assign(n,-1);
    for(int i=0; i<q; i++){
        int c,u,v; cin>>c>>u>>v;
        if (c == 1){
            join(u,v);
        } else {
            int pu = parent(u), pv = parent(v);
            if (pu == pv)cout << 'Y' << endl;
            else cout << 'T' << endl;
        }
    }
    return 0;
}
