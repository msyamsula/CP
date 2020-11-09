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
vl arr;

void solve(){
    cin>>n>>m;
    arr.resize(0);
    for(ll i=0; i<n; i++){
        ll temp; cin>>temp;
        arr.push_back(temp);
    }

    set<ll> s;
    vl unique(n, 0);
    for(ll i=n-1; i>=0; i--){
        if (s.find(arr[i]) == s.end()) s.insert(arr[i]);
        unique[i] = s.size();
    }

    for(ll i=0; i<m; i++){
        ll temp; cin>>temp;
        temp--;
        cout << unique[temp] << endl;
    }
}

int main(){
    solve();
    // int tc; cin>>tc;
    // for(int i=0; i<tc; i++){
    //     cout << "Case #" << i+1 << ": ";
    //     solve();
    // }

    return 0;
}
