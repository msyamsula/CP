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
vl arr;
set<ll> odd,even;

void solve(){
    cin>>n;
    arr.resize(0);
    odd.clear(); even.clear();
    for(ll i=0; i<n; i++){
        ll temp; cin>>temp;
        arr.push_back(temp);
        if (temp&1) odd.insert(i);
        else even.insert(i);
    }

    ll target;
    if (odd.size()==1){
        for(ll num : odd){
            cout << num+1 << endl;
            break;
        }
    } else {
        for(ll num : even){
            cout << num+1 << endl;
            break;
        }
    }
}

int main(){
    solve();
    // int tc; cin>>tc;
    // for(int i=0; i<tc; i++){
    //     cout << "Case #" << i+1 << ": ";
    // }

    return 0;
}
