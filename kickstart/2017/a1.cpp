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
#define modulo 1000000007

ll R, C;
void solve(){
    cin>>R>>C;
    ll max_size = min(R,C);
    ll rect = R/2;
    rect *= (R+1)/2; rect%=modulo;
    rect *= (C/2); rect%=modulo;
    rect *= (C+1)/2; rect%=modulo;
    for(ll i=2; i<max_size; i++){
        rect += i-1; rect%=modulo;
    }

    cout << rect << endl;
}

int main(){
    int tc; cin>>tc;
    for(int i=0; i<tc; i++){
        cout << "Case #" << i+1 << ": ";
        solve();
    }

    return 0;
}
