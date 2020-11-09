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

string a,b;

void solve(){
    cin>>a>>b;
    ll n = a.size();
    ll ans = 0;
    for(ll i=0; i<n; i++){
        if (tolower(a[i]) < tolower(b[i])){
            ans--;
            break;
        } else if (tolower(a[i]) > tolower(b[i])){
            ans++;
            break;
        }
    }

    cout << ans << endl;
}

int main(){
    // int tc; cin>>tc;
    ll tc=1;
    for(int i=0; i<tc; i++){
        // cout << "Case #" << i+1 << ": ";
        solve();
    }

    return 0;
}
