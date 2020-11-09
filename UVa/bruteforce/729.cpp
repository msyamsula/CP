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

ll N,H;
vl cur_bitset;
vvl all;
// vector<bitset<16>> all;
void search(ll idx, ll cnt){
    if (cnt == H){
        all.push_back(cur_bitset);
        // for(ll i=0; i<cur_bitset.size(); i++){
        //     cout << cur_bitset[i];
        // }
        // cout << endl;
        return;
    }


    for(ll i=idx; i<=N-H+cnt; i++){
        if (cur_bitset[i] == 1) continue;
        cur_bitset[i]=1;
        search(i, cnt+1);
        cur_bitset[i]=0;
    }
}

void solve(){
    cin>>N>>H;
    cur_bitset.resize(0); cur_bitset.assign(N, 0);
    all.resize(0);
    search(0,0);
    for(ll i=all.size()-1; i>=0; i--){
        for(ll num : all[i]){
            cout << num;
        }
        cout << endl;
    }
    // cout << endl;
}

int main(){
    int tc; cin>>tc;
    for(int i=0; i<tc; i++){
        // cout << "Case #" << i+1 << ": ";
        if (i!=0) cout << endl;
        solve();
    }

    return 0;
}
