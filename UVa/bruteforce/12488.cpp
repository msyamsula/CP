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
vl start,finish;
void solve(){
    start.resize(0); finish.resize(0);
    for(ll i=0; i<n; i++){
        ll temp; cin>>temp;
        start.push_back(temp);
    }

    for(ll i=0; i<n; i++){
        ll temp; cin>>temp;
        finish.push_back(temp);
    }

    // for(ll num : start){
    //             cout << num << ' ';
    //         }
    //         cout << endl;

    ll ans = 0;
    // cout << "tes" << endl;
    for(ll i=0; i<n; i++){
        if (start[i]==finish[i]) continue;
        for(ll j=i; j<n; j++){
            if (start[j] == finish[i]){
                start.erase(start.begin()+j);
                start.insert(start.begin()+i,finish[i]);
                ans += (j-i>0)?j-i:0;
            }

            // for(ll num : start){
            //     cout << num << ' ';
            // }
            // cout << endl;

        }
    }

    cout << ans << endl;
}

int main(){
    while(cin>>n){
        solve();
    }

    return 0;
}
