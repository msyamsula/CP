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

vs arr;
vector<iii> edges;
vi ufd;

bool comp(iii a, iii b){
    if (a.second != b.second){
        return (a.second < b.second);
    } else if (a.first.first != a.first.first){
        return (a.first.first < b.first.first);
    }

    return (a.first.second < a.first.second);
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
    int n; cin>>n;
    arr.resize(0); arr.assign(n, "0000");
    edges.resize(0); ufd.resize(0); ufd.assign(n,-1);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    long long minim = MAXLL;
    for(int i=0; i<n; i++){
        long long step = 0;
        for(int j=0; j<4; j++){
            int up = int(arr[i][j])-'0';
            up = (up < 0) ? up+10 : up;
            int down = 10-up;
            down = (down < 0) ? down+10 : down;
            step += min(up, down);
        }
        minim = min(minim, step);
    }


    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            int u = i, v = j;
            string code1 = arr[i], code2 = arr[j];
            int step = 0;
            for(int ii=0; ii<4; ii++){
                int c1 = int(code1[ii])-'0', c2 = int(code2[ii]) - '0';
                // step += abs(c1-c2);
                int up = c1-c2;
                up = (up < 0) ? up+10 : up;
                int down = 10-up;
                down = (down < 0) ? down+10 : down;
                step += min(up, down);
            }
            edges.push_back({{u,v},step});
            edges.push_back({{v,u},step});
        }
    }

    sort(edges.begin(), edges.end(), comp);

    for(iii temp : edges){
        int u = temp.first.first, v = temp.first.second, w = temp.second;
        int pu = parent(u), pv = parent(v);
        if (pu == pv) continue;
        // cout << u << ' ' << v << ' ' << w << endl;
        join(u,v);
        minim += w;
    }

    cout << minim << endl;
}

int main(){
    int tc; cin>>tc;
    for(int i=0; i<tc; i++){
        // cout << "Case #" << i+1 << ": ";
        solve();
    }

    return 0;
}