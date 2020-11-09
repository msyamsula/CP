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

ll n,m;
vvl constraints;
vvl all;

void solve(){
    constraints.resize(0);
    all.resize(0);
    for(ll i=0; i<m; i++){
        ll a,b,c; cin>>a>>b>>c;
        constraints.push_back({a,b,c});
    }

    vl arr;
    for(ll i=0; i<n; i++){
        arr.push_back(i);
    }


    ll cnt = 1;
    for(ll i=n; i>=1; i--){
        cnt*=i;
    }

    do{
        all.push_back(arr);
        for(ll i=0; i<m; i++){
            ll u = constraints[i][0], v = constraints[i][1], c = constraints[i][2];
            if ( c < 0){
                if (abs(arr[u]-arr[v])<abs(c)){
                    cnt--;
                    break;
                }
            } else if (c>0){
                if (abs(arr[u]-arr[v])>abs(c)){
                    cnt--;
                    break;
                }
            }

        }
    } while(next_permutation(arr.begin(), arr.end()));

    cout << cnt << endl;

    // for(vl temp : all){
    //     for(ll num : temp){
    //         cout << num << ' ';
    //     }
    //     cout << endl;
    // }
    // cout << endl;

}

int main(){
    while(cin>>n>>m){
        if (!n && !m) break;
        solve();
    }
    // int tc; cin>>tc;
    // for(int i=0; i<tc; i++){
    //     cout << "Case #" << i+1 << ": ";
    //     solve();
    // }

    return 0;
}
