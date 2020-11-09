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
    map<ll, ll> mem;
    for(ll i=0; i<n; i++){
        ll temp; cin>>temp;
        mem[temp]++;
    }

    auto it = mem.begin();
    ll g = 0;
    for(it=mem.begin(); it!=mem.end(); it++){
        ll e = it->first, tot = it->second;
        // cout << e << ' ' << tot << endl;
        g += tot/e; it->second = tot%e;
    }


    ll sum = 0;
    for(it=mem.begin(); it!=mem.end(); it++){
        ll e = it->first, tot = it->second;
        sum += tot;
        if (sum>=e){
            g+=sum/e;
            sum %= e;
        }
    }

    cout << g << endl;
}

int main(){
    int tc; cin>>tc;
    for(int i=0; i<tc; i++){
        // cout << "Case #" << i+1 << ": ";
        solve();
    }

    return 0;
}
