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
    arr.resize(0);
    cin>>n;
    set<ll> s;
    for(ll i=0; i<n; i++){
        ll temp; cin>>temp;
        if (s.find(temp) == s.end()) arr.push_back(temp);
        s.insert(temp);
    }

    sort(arr.begin(), arr.end());
    ll prev = arr[0];
    ll max_len = 1;
    ll len=1;
    n = arr.size();
    for(ll i=1; i<n; i++){
        // cout << len << endl;
        if (arr[i]-prev <= 1){
            len++;
        } else {
            len = 1;
        }
        max_len = max(max_len, len);
        prev = arr[i];
    }
    // cout << max_len << ' ' << n << s.size() << endl;

    if (max_len == n){
        cout << "YES" << endl;
        return;
    }

    cout << "NO" << endl;

}

int main(){
    int tc; cin>>tc;
    for(int i=0; i<tc; i++){
        // cout << "Case #" << i+1 << ": ";
        solve();
    }

    return 0;
}
