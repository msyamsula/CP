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
vl a;
vl w;

void solve(){
    cin>>n>>k;
    a.resize(0); w.resize(0);
    for(ll i=0; i<n; i++){
        ll temp; cin>>temp;
        a.push_back(temp);
    }
    sort(a.begin(), a.end());

    for(ll i=0; i<k; i++){
        ll temp; cin>>temp;
        w.push_back(temp);
    }
    sort(w.begin(), w.end());

    ll ans = 0;
    for(ll i=0; i<k; i++){
        // cout << ans << endl;
        // cout << "a: ";
        // for(ll num : a){
        //     cout << num << ' ';
        // }
        // cout << endl;
        if (w[i] == 1){
            ans += (*a.rbegin())*2;
            ll nidx = a.size()-1;
            a.erase(a.begin()+nidx);
            continue;
        }
        ans += (*a.rbegin())+(*a.begin());
        ll nidx = a.size()-1;
        a.erase(a.begin()+nidx);
        // cout << "wi: " << w[i] << ' ' << i << endl;
        for(ll j=0; j<w[i]-1; j++){
            // cout << a.size() << ' ' << j << endl;
            a.erase(a.begin());
        }
    }

    cout << ans << endl;
    //  << endl;

}

int main(){
    int tc; cin>>tc;
    for(int i=0; i<tc; i++){
        // cout << "Case #" << i+1 << ": ";
        solve();
    }

    return 0;
}
