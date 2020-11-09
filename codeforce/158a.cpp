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
    // int tc; cin>>tc;
    // for(int i=0; i<tc; i++){
    //     cout << "Case #" << i+1 << ": ";
    //     solve();
    // }
    ll n,k; cin>>n>>k; k--;
    vl arr; arr.assign(n,0);
    ll bound;
    for(ll i=0; i<n; i++){
        cin>>arr[n-1-i];
        if (i==k) bound = arr[n-1-i];
    }

    if (bound == 0){
        auto it = upper_bound(arr.begin(),arr.end(),bound);
        ll pass = distance(it, arr.end());
        cout << pass << endl;
        return 0;
    }

    auto it = lower_bound(arr.begin(), arr.end(), bound);
    ll pass = distance(it, arr.end());
    cout << pass << endl;

    return 0;
}
