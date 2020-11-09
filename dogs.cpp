#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef tuple<int, int, int, int> iiii;
typedef map<iiii, int> miiiii;

int dp(int pos, int sc, int tot, int idx, int k, vii dogs, miiiii &mem){
    iiii state = make_tuple(pos,sc,tot,idx);
    if (mem.find(state) != mem.end()){
        cout << "memo" << endl;
        return mem.at(state);
    }

    if (tot == k) return mem[state]=0;
    if (idx == dogs.size()) return mem[state]=1<<30;

    int pt = (dogs[idx].second != sc) ? pos+dogs[idx].first : dogs[idx].first - pos;
    int take = pt + dp(dogs[idx].first, dogs[idx].second, tot+1, idx+1, k, dogs, mem);
    int leave = dp(pos, sc, tot, idx+1, k, dogs, mem);
    return mem[state]=min(take,leave);
}

void solve(int tc){
    int n, k; cin>>n>>k;
    vii dogs(n);
    // for(int i=0; i<n; i++){
    //     cout << dogs[i].first << ' ' << dogs[i].second << endl;
    // }
    for (int i=0; i<n; i++){
        cin>>dogs[i].first;
    }

    for (int i=0; i<n; i++){
        cin>>dogs[i].second;
    }


    sort(dogs.begin(), dogs.end());

    miiiii mem;
    int ans = dp(0,0,0,0,k,dogs,mem);

    cout << "Case #" << tc << ": " << ans << endl;
}

int main(){
    int tc; cin>>tc;
    for(int i=0; i<tc; i++){
        solve(i+1);
    }

    return 0;
}