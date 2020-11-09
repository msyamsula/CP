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
vector<pair<double, double>> arr;
vector<pair<pair<double,double>, double>> edges;

bool comp(pair<pair<double, double>, double> a, pair<pair<double, double>, double> b){
    if (a.second != b.second){
        return (a.second < b.second);
    } else if (a.first.first != b.first.first){
        return (a.first.first < b.first.first);
    }

    return (a.first.second < b.first.second);
}

int parent(int a){
    if(ufd[a]<0) return a;
    return parent(ufd[a]);
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

void solve(){
    int n; cin>>n;
    arr.resize(0); ufd.resize(0); ufd.assign(n, -1);
    edges.resize(0);
    // cout << n << endl;
    for(int i=0; i<n; i++){
        double x,y; cin>>x>>y;
        for(int j=0; j<arr.size(); j++){
            double u = arr.size(), v=j;
            double w = hypot(abs(x-arr[v].first), abs(y-arr[v].second));
            edges.push_back({{u,v},w});
            edges.push_back({{v,u},w});
        }
        arr.push_back({x,y});
    }

    sort(edges.begin(), edges.end(), comp);

    // for(pair<double, double> a : arr){
    //     cout << a.first << ' ' << a.second << endl;
    // }
    // cout << endl;

    long double minim = 0;
    for(pair<pair<double, double>, double> temp : edges){
        int u = temp.first.first, v = temp.first.second;
        double w = temp.second;
        // cout << u << ' ' << v << ' ' << w << endl;
        int pu = parent(u), pv = parent(v);
        if(pu == pv) continue;
        join(u,v);
        minim += w;
    }

    cout << fixed << setprecision(2) << minim << endl;
}

int main(){
    int tc; cin>>tc;
    for(int i=0; i<tc; i++){
        // cout << "Case #" << i+1 << ": ";
        if(i!=0) cout << endl;
        solve();
    }

    return 0;
}