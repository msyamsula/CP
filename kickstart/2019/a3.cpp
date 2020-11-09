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

ll n,q;
vvl query;

bool comp(vl a, vl b){
    if (a[0]!=b[0]) return a[0]<b[0];
    return a[1]<b[1];
}

void solve(){
    cin>>n>>q;
    query.resize(0);
    for(ll i=0; i<q; i++){
        ll left,right; cin>>left>>right;
        left--; right--;
        query.push_back({left,right});
    }

    sort(query.begin(),query.end(), comp);
    ll start=-MAXLL, end=0;
    
}

int main(){
    int tc; cin>>tc;
    for(int i=0; i<tc; i++){
        cout << "Case #" << i+1 << ": ";
        solve();
    }
    

    return 0;
}
