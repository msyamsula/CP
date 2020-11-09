#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
typedef vector<int> vi;
typedef vector<iii> viii;
typedef map<vi, int> mvii;

int parent(int node, vi par){
    if (par[node] < 0) return node;
    return parent(par[node],  par);
}

void join(int n1, int n2, vi &par){
    int p1 = parent(n1,par), p2 = parent(n2,par);
    if (p1 == p2) return;

    if (par[p1] <= par[p2]){
        par[p1] = par[p1]+par[p2];
        par[p2] = p1;
    } else {
        par[p2] = par[p2]+par[p1];
        par[p1] = p2;
    }
}

void solve(int tc){
    int n,m;
    cin>>n>>m;
    viii edges;
    for (int i=1; i<=n-1; i++){
        for (int j=i+1; j<=n; j++){
            iii value = {2,i,j};
            edges.push_back(value);
            // edges[value] = 2;
        }
    }

    for (int i=0; i<m; i++){
        int s,e;
        cin>>s>>e;
        iii value = {1,s,e};
        edges.push_back(value);
    }

    sort(edges.begin(),edges.end());
    vi par(n+1,-1);

    // cout << "par " << parent(2,par) << endl;
    int mst = 0;
    for(int i=0; i<edges.size(); i++){
        iii curEdge = edges[i];
        int s = get<1>(curEdge), e = get<2>(curEdge), w = get<0>(curEdge);
        // cout << s << ' ' << e << ' ' << w << endl;
        if (parent(s,par) == parent(e,par)) continue;
        mst+=w;
        join(s,e,par);
    }
    // join(1,2,par);
    // join(2,3,par);

    // cout << "par" << endl;
    // for (int i=1; i<n+1; i++){
    //     cout << parent(i,par) << ' ';
    // }
    // cout << endl;

    cout << "Case #" << tc << ": " << mst << endl;

    // return 0;
}

int main(){
    int tc; cin>>tc;
    for(int i=0; i<tc; i++){
        solve(i+1);
    }

    return 0;
}