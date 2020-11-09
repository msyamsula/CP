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
    ll n,k; cin>>n>>k;
    string s; cin>>s;
    ll count = 0;
    for(ll i=1; i<n; i++){
        for(ll j=max(0ll, i-k); j<i; j++){
            if (s[j]==s[i]){
                // cout << s[i] << endl;
                count++;
                break;
            }
        }
    }

    cout << count << endl;
}

int main(){
    int tc; cin>>tc;
    for(int i=0; i<tc; i++){
        cout << "Case " << i+1 << ": ";
        solve();
    }

    return 0;
}
