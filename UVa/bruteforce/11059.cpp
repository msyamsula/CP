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
vl ps;
vl max_neg, min_pos;
void solve(){
    arr.resize(0);
    ps.resize(0); ps.assign(n+1, 1);
    max_neg.resize(0); max_neg.assign(n+1, -MAXLL);
    min_pos.resize(0); min_pos.assign(n+1, 1);
    for(ll i=0; i<n; i++){
        ll temp; cin>>temp;
        arr.push_back(temp);
        if (arr[i] != 0){
            ps[i+1]=ps[i]*arr[i];
            if (ps[i+1] < 0){
                max_neg[i+1] = max(max_neg[i], ps[i+1]);
                min_pos[i+1] = min_pos[i];
            }
            if (ps[i+1] > 0){
                min_pos[i+1] = min(min_pos[i], ps[i+1]);
                max_neg[i+1] = max_neg[i];
            }
        } else {
            ps[i+1]=1;
            max_neg[i+1] = -MAXLL;
        }
    }

    ll ans = 0;
    for(ll i=0; i<n; i++){
        if (arr[i] == 0) continue;
        if (ps[i+1] > 0) ans = max(ans, ps[i+1]/min_pos[i]);
        else ans = max(ans, ps[i+1]/max_neg[i]);
    }

    // for(ll num : ps){
    //     cout << num << ' ';
    // }
    // cout << endl;

    // for(ll num : max_neg){
    //     cout << num << ' ';
    // }
    // cout << endl;

    // for(ll num : min_pos){
    //     cout << num << ' ';
    // }
    // cout << endl;

    cout << ans << '.' << endl;

}

int main(){
    ll i = 1;
    while(cin>>n){
        // if (i!=0) cout << endl;
        cout << "Case #"<< i << ": The maximum product is ";
        solve();
        cout << endl;
        i++;
    }
    // int tc; cin>>tc;
    // for(int i=0; i<tc; i++){
    //     cout << "Case #" << i+1 << ": ";
    //     solve();
    // }

    return 0;
}
