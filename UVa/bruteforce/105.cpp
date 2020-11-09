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

vl arr;

void solve(){

}

int main(){
    ll len = 10000;
    arr.assign(len+1, 0);
    ll l,h,r;
    ll maxr=-1;
    while(cin>>l>>h>>r){
        maxr = max(maxr, r);
        for(ll i=l; i<r; i++){
            arr[i] = max(arr[i], h);
        }
        // for(ll num : arr){
        //     cout << num << ' ';
        // }
        // cout << endl;
    }

    if (maxr+1<=len) arr[maxr+1] = -1;
    // for(ll num : arr){
    //     cout << num << ' ';
    // }
    // cout << endl;

    ll cur=0;
    bool run = false;
    for(ll i=0; i<=len; i++){
        if (arr[i]==-1) break;
        if (arr[i] != cur){
            cur = arr[i];
            if (run) cout << ' ';
            cout << i << ' ' << arr[i];
            run = true;
        }
    }
    cout << endl;

    
    // int tc; cin>>tc;
    // for(int i=0; i<tc; i++){
    //     cout << "Case #" << i+1 << ": ";
    //     solve();
    // }

    return 0;
}
