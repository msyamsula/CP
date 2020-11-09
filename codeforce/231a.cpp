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


void solve(){
    
}

int main(){
    ll n;cin>>n;
    ll ans = 0;
    for(ll i=0; i<n; i++){
        ll sum = 0;
        for(ll j=0; j<3; j++){
            ll temp; cin>>temp;
            sum += temp;
        }
        if (sum>1) ans++;
    }
    cout << ans << endl;

    return 0;
}
