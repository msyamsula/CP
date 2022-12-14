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
vl coins;

void solve(){
    cin>>n;
    coins.resize(0);
    for(ll i=0; i<n; i++){
        ll temp; cin>>temp;
        coins.push_back(temp);
    }

    ll state = 0, ans = 0;
    coins.push_back(MAXLL);
    for(ll i=0; i<n; i++){
        ll next = state + coins[i];
        if (next<coins[i+1]){
            state += coins[i];
            ans++;
        }
    }

    cout << ans << endl;
}

int main(){
    int tc; cin>>tc;
    for(int i=0; i<tc; i++){
        // cout << "Case #" << i+1 << ": ";
        solve();
    }

    return 0;
}
