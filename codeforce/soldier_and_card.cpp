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

ll n,ka,kb;
vl ca, cb;

bool wars(vl &ca, vl &cb){
    if (ca.size()==0 || cb.size()==0) return 0;
    ll a = ca[0], b = cb[0];
    ca.erase(ca.begin()); cb.erase(cb.begin());
    if (a>b){
        ca.push_back(b);
        ca.push_back(a);
    } else {
        cb.push_back(a);
        cb.push_back(b);
    }
    return 1;
}

void solve(){
    cin>>n;
    cin>>ka;
    ca.resize(0); ca.assign(ka, 0);
    for(ll i=0; i<ka; i++){
        cin>>ca[i];
    }

    cin>>kb;
    cb.resize(0); cb.assign(kb, 0);
    for(ll i=0; i<kb; i++){
        cin>>cb[i];
    }

    vvl start_state;
    start_state.push_back(ca);
    start_state.push_back(cb);
    // cout << "start_state: " << start_state.size() << endl;
    // for(vl arr : start_state){
    //     for(ll num : arr){
    //         cout << num << ' ';
    //     }
    //     cout << endl;
    // }

    ll ans = 0;

    vvl state;
    do {
        if (wars(ca, cb)){
            state.resize(0);
            state.push_back(ca);
            state.push_back(cb);
            ans++;

            // cout << "war ke: " << ans << endl;
            // for(vl arr : state){
            //     for(ll num : arr){
            //         cout << num << ' ';
            //     }
            //     cout << endl;
            // }


            if (state == start_state){
                cout << -1 << endl;
                return;
            }
        } else break;
    }
    while (state[0].size() > 0 && state[1].size() > 0);

    // cout << "ans: ";
    cout << ans << ' ';
    ll winner = (ca.size()==0) ? 2 : 1;
    cout << winner << endl;

}

int main(){
    solve();
    // int tc; cin>>tc;
    // for(int i=0; i<tc; i++){
    //     cout << "Case #" << i+1 << ": ";
    // }

    return 0;
}
