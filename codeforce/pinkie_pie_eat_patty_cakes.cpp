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
map<ll, ll> vf;
map<ll, set<ll>> fv;

void solve(){
    fv.clear();
    vf.clear();
    cin>>n;
    for(ll i=0; i<n; i++){
        ll temp; cin>>temp;
        vf[temp]++;
    }

    for(pair<ll, ll> p : vf){
        ll v = p.first, f = p.second;
        fv[f].insert(v);
    }

    if (vf.size() == 1){
        cout << 0 << endl;
        return;
    }

    for(pair<ll, set<ll>> p : fv){
        cout << p.first << ": ";
        for(ll num : p.second){
            cout << num << ' ';
        }
        cout << endl;
    }

    ll sum = 0;
    n = fv.begin()->second.size();
    cout << "n: " << n << endl;
    auto ita = fv.begin();
    ita++;
    for(auto it=ita; it != fv.end(); it++){
        for(ll num : it->second){
            sum += floor((double)n/((it->first)-1));
            n+=it->first;
        }
        // cout << sum << endl;
    }
    ll ans = floor(double(sum)/(fv.size()));
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
