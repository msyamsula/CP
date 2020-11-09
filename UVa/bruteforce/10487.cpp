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

vl arr;

void solve(ll n){
    arr.resize(0);
    for(ll i=0; i<n; i++){
        ll ntemp; cin>>ntemp;
        arr.push_back(ntemp);
    }

    vl sums;
    for(ll i=0; i<n-1; i++){
        for(ll j=i+1; j<n; j++){
            if (arr[i] == arr[j]) continue;
            sums.push_back(arr[i]+arr[j]);
        }
    }
    sort(sums.begin(),sums.end());

    ll q; cin>>q;
    for(ll i=0; i<q; i++){
        ll qq; cin>>qq;
        // cout << qq << endl;
        ll minim = MAXLL;
        ll ans;
        for(ll j=0; j<sums.size(); j++){
            if (abs(qq-sums[j]) < minim){
                minim = qq-sums[j];
                ans = sums[j];
            }
        }
        cout << "Closest sum to " << qq << " is " << ans << '.' << endl;
    }
}

int main(){
    ll n;
    ll i=0;
    while(cin>>n){
        if (n==0) break;
        cout << "Case " << i+1 << ":\n";
        solve(n);
        i++;
    }

    // int tc; cin>>tc;
    // for(int i=0; i<tc; i++){
    //     solve();
    // }

    return 0;
}
