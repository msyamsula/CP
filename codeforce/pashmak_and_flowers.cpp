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

void solve(){
    cin>>n;
    arr.resize(0);
    map<ll, ll> flowers;
    for(ll i=0; i<n; i++){
        ll temp; cin>>temp;
        flowers[temp]++;
        // arr.push_back(temp);
    }

    if (flowers.size()==1){
        ll sz = flowers.begin()->second;
        cout << 0 << ' ' << (sz*(sz-1))/2 << endl;
        return;
    }

    auto last = flowers.rbegin()->second;
    auto first = flowers.begin()->second;

    // cout << flowers.rbegin()->first << endl;
    // cout << flowers.begin()->first << endl;

    cout << (flowers.rbegin()->first - flowers.begin()->first) << ' ' << last*first << endl;

}

int main(){
    solve();
    // int tc; cin>>tc;
    // for(int i=0; i<tc; i++){
    //     cout << "Case #" << i+1 << ": ";
    // }

    return 0;
}
