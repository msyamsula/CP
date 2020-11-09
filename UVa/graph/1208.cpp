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

vector<iii> edges;
vector<int> ufd;

bool comp(iii a, iii b){
    if (a.second != b.second){
        return (a.second < b.second);
    } else if (a.first.first != b.first.first){
        return (a.first.first < b.first.first);
    }

    return (a.first.second < b.first.second);
}

int parent(int a){
    if(ufd[a] < 0 ) return a;
    return parent(ufd[a]);
}

void join(int a, int b){
    int pa = parent(a), pb=parent(b);
    if (pa == pb) return;

    if(ufd[pa]<=ufd[pb]){
        ufd[pa] += ufd[pb];
        ufd[pb] = pa;
    } else {
        ufd[pb] += ufd[pa];
        ufd[pa] = pb;
    }
}

void solve(){
    int n; cin>>n;
    edges.resize(0);
    ufd.resize(0); ufd.assign(n,-1);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            int u = i, v = j;
            int w; char b;
            if (j==n-1) cin>>w;
            else cin>>w>>b;

            if (w==0) continue;
            edges.push_back({{u,v},w});
        }
    }
    // cout << "tes" << endl;

    sort(edges.begin(), edges.end(), comp);
    long long min = 0;
    for(iii temp : edges){
        int u = temp.first.first, v = temp.first.second, w = temp.second;
        int pu = parent(u), pv = parent(v);
        if (pu == pv) continue;
        join(u,v);
        min += w;
        cout << char(u+65) << '-' << char(v+65) << ' ' << w << endl;
    }

    // cout << min << endl;

}

int main(){
    int tc; cin>>tc;
    for(int i=0; i<tc; i++){
        cout << "Case " << i+1 << ":\n";
        solve();
    }

    return 0;
}