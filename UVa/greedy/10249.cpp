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

ll m,n;
vl table,av,team;

void solve(){
    cin>>m>>n;
    table.resize(0); table.assign(n,0);
    av.resize(0); av.assign(n,0);
    team.resize(0); team.assign(m,0);
    for(ll i=0; i<m; i++){
        cin>>team[i];
    }

    for(ll i=0; i<n; i++){
        cin>>table[i];
    }
}

int main(){
    int tc; cin>>tc;
    for(int i=0; i<tc; i++){
        cout << "Case #" << i+1 << ": ";
        solve();
    }

    return 0;
}
