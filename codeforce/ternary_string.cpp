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

string s;

void solve(){
    cin>>s;
    // cout << s << endl;
    vvl block;
    ll n=s.size();
    ll prev = 0;
    for(ll i=0; i<=n; i++){
        if (i==n){
            block.rbegin()->push_back(i-1);
            continue;
        }

        if (i == 0){
            block.push_back({s[i]-'0', i});
            prev = s[i]-'0';
            continue;
        }

        if (s[i]-'0' == prev) continue;
        block.rbegin()->push_back(i-1);
        block.push_back({s[i]-'0', i});
        prev = s[i]-'0';
    }

    // for(vl arr : block){
    //     for(ll num : arr){
    //         cout << num << ' ';
    //     }
    //     cout << endl;
    // }


    ll ans = MAXLL;
    for(ll i=0; i<block.size(); i++){
        set<ll> cset;
        ll val = block[i][0];
        cset.insert(val);
        ll start = block[i][1], end = block[i][2];
        ll len = end-start+1;
        ll left = start-1, right = end+1;
        if (left < 0 || right >=n) continue;
        cset.insert(s[left]-'0');
        cset.insert(s[right]-'0');
        if (cset.size() == 3){
            ans = min(ans, len+2);
        }
    }

    cout << ((ans==MAXLL)?0:ans) << endl;
}

int main(){
    int tc; cin>>tc;
    for(int i=0; i<tc; i++){
        // cout << "Case #" << i+1 << ": ";
        solve();
    }

    return 0;
}
