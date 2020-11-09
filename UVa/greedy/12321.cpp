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

ll L,G;
vvl gas_coverage;

void solve(){
    // cout << L << ' ' << G << endl;
    gas_coverage.resize(0);
    for(ll i=0; i<G; i++){
        ll x,r; cin>>x>>r;
        ll left = max(0ll,x-r), right = min(L, x+r);
        gas_coverage.push_back({left,right});
    }

    sort(gas_coverage.begin(), gas_coverage.end());

    // cout << "gas_coverage:" << endl;
    // for(vl a : gas_coverage){
    //     for(ll num : a){
    //         cout << num << ' ';
    //     }
    //     cout << endl;
    // }
    // cout << endl;

    if (gas_coverage[0][0] > 0){
        cout << -1 << endl;
        return;
    }

    ll start=-1, end=0;
    ll ans = 0;
    for(ll i=0; i<G; i++){
        // cout << "i: " << i << ", end: " << end << endl;
        ll max_right = end;
        ll choice = -1;
        ll j;
        // cout << "j: ";
        for(j=i; j<G; j++){
            // cout << j << ' ';
            ll left = gas_coverage[j][0], right = gas_coverage[j][1];
            if (left > end) break;
            if (right <= end) continue;
            if (right > max_right){
                max_right = right;
                choice = j;
            }
        }
        // cout << endl;
        // cout << choice << endl;
        if (choice == -1){
            cout << -1 << endl;
            return;
        }
        i = j-1;
        end = max_right;
        ans++;
        if (end >= L) break;
    }

    if (end<L){
        cout << -1 << endl;
        return;
    }

    cout << G-ans << endl;
}

int main(){
    while(cin>>L>>G){
        if(!L && !G) break;
        solve();
    }
    // int tc; cin>>tc;
    // for(int i=0; i<tc; i++){
    //     cout << "Case #" << i+1 << ": ";
    //     solve();
    // }

    return 0;
}
