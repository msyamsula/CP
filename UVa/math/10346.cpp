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

ll n,k;

void solve(){
    // cout << "n: " << n << endl;
    ll ans = 0;
    while(n>=k){
        n += 1-k;
        ans += k;
    }
    ans += n;
    cout << ans << endl;
}

int main(){
    while(cin>>n>>k){
        solve();
    }

    return 0;
}
