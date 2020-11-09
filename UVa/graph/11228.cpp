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

vector<ii> arr;
vector<pair<ii, double>> edges;
vi ufd;

bool comp(pair<ii, double> a , pair<ii, double> b){
    if (a.second != b.second){
        return (a.second < b.second);
    } else if (a.first.first != b.first.first){
        return (a.first.first < b.first.first);
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

void solve(){
    int n,r; cin>>n>>r;
    arr.resize(0); edges.resize(0); ufd.resize(0); ufd.assign(n, -1);
    for(int i=0; i<n; i++){
        int x,y; cin>>x>>y;
        for(int j=0; j<arr.size(); j++){
            int u = i, v = j;
            double w = hypot(abs(x-arr[j].first), abs(y-arr[j].second));
            edges.push_back({{u,v},w});
            edges.push_back({{v,u},w});
        }
        arr.push_back({x,y});
    }

    sort(edges.begin(), edges.end(), comp);

    long double road = 0, rail = 0;
    int nrail = 0;
    for(pair<ii, double> temp : edges){
        int u = temp.first.first, v = temp.first.second;
        double w = temp.second;
        // cout << u << ' ' << v << ' ' << w << endl;
        int pu = parent(u), pv = parent(v);
        if (pu == pv) continue;
        if (w > r){
            rail+=w;
            nrail++;
        }
        else road += w;
        join(u,v);
    }

    cout << nrail+1 << ' ' << round(road) << ' ' << round(rail) << endl;
}

int main(){
    int tc; cin>>tc;
    for(int i=0; i<tc; i++){
        cout << "Case #" << i+1 << ": ";
        solve();
    }

    return 0;
}