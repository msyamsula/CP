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
vector<pair<ll,ll>> ans;

bool check(ll num){
    string s = to_string(num);
    set<char> sc;
    for(ll i=0; i<s.size(); i++){
        sc.insert(s[i]);
    }

    return sc.size() == s.size();
}

void solve(){
    cin>>n;
    // cout << n << endl;
    ans.resize(0);
    for(ll i=1; i<=100000; i++){
        if(check(i)){
            ll j=i*n;
            if (check(j)) ans.push_back({j,i});
        }
    }

    for(pair<ll, ll> temp : ans){
        cout << temp.first << " / " << temp.second << " = " << n << endl;
    }
}

int main(){
    int tc; cin>>tc;
    for(int i=0; i<tc; i++){
        // cout << "Case #" << i+1 << ": ";
        if(i!=0) cout << endl;
        solve();
    }

    return 0;
}
