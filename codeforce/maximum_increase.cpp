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

ll n;

void solve(){
    cin>>n;
    ll prev = 0;
    ll cnt = 0;
    ll ans = cnt;
    for(ll i=0; i<n; i++){
        ll cur; cin>>cur;
        if (cur>prev) cnt++;
        else{
            cnt = 1;
        }
        ans = max(ans, cnt);
        prev = cur;
    }

    cout << ans << endl;
}

int main(){
    solve();

    return 0;
}
