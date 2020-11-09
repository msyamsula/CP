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

ll n,d,r;
vl morning, night;

bool comp(ll a, ll b){
    return a>b;
}

void solve(){
    morning.resize(0);
    for(ll i=0; i<n; i++){
        ll temp; cin>>temp;
        morning.push_back(temp);
    }

    night.resize(0);
    for(ll i=0; i<n; i++){
        ll temp; cin>>temp;
        night.push_back(temp);
    }

    sort(morning.begin(),morning.end());
    sort(night.begin(),night.end(),comp);

    ll overtime = 0;
    for(ll i=0; i<n; i++){
        ll add  = (morning[i]+night[i]-d)*r;
        if (add > 0) overtime += add;
    }

    cout << overtime << endl;
}

int main(){
    while(cin>>n>>d>>r){
        if(!n && !d && !r) break;
        solve();
    }
    // int tc; cin>>tc;
    // for(int i=0; i<tc; i++){
    //     cout << "Case #" << i+1 << ": ";
    //     solve();
    // }

    return 0;
}
