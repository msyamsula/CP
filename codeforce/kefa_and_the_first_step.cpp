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
    ll num = 0;
    ll cnt = 0;
    ll max_cnt = 0;
    for(ll i=0; i<n; i++){
        ll temp; cin>>temp;
        if (temp>=num){
            cnt++;
        } else {
            cnt = 1;
        }
        max_cnt = max(max_cnt, cnt);
        num = temp;
    }

    cout << max_cnt << endl;
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
