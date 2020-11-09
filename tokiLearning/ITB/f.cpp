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

ll N,Q;

void solve(){
    cin>>N;
    unordered_set<ll> s;
    for(ll i=0; i<N; i++){
        ll temp; cin>>temp;
        s.insert(temp);
    }

    vl arr;
    for(ll i=0; i<N; i++){
        ll temp; cin>>temp;
        arr.push_back(temp);
    }

    cin>>Q;
    for(ll q=0; q<Q; q++){
        ll target; cin>>target;
        ll ans = 0;
        for(ll i=0; i<N; i++){
            ll search = target-arr[i];
            if (s.find(search) != s.end()) ans++;
        }
        cout << ans << endl;
    }
}

int main(){
    int tc; cin>>tc;
    for(int i=0; i<tc; i++){
        // cout << "Case #" << i+1 << ": ";
        solve();
    }

    return 0;
}
