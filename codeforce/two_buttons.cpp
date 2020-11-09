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

ll n,m;

void solve(){
    cin>>n>>m;
    ll step = 0;
    while(n<m && !(m&1)){
        m/=2;
        step++;
    }

    while(n<m && (m&1)){
        n*=2;
        step++;
    }

    step += n-m;
    cout << step << endl;
}

int main(){
    solve();
    // int tc; cin>>tc;
    // for(int i=0; i<tc; i++){
    //     cout << "Case #" << i+1 << ": ";
    // }

    return 0;
}
