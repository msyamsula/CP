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

ll k, n;
vl arr, used, cur_posiibilities;;
// vvl all_posibilities;

void search(ll idx, ll size){
    // cout << idx << ' ' << arr[idx] << endl;
    if (size == 6){
        // cout << cur_posiibilities.size()<< endl;
        for(ll i=0; i<cur_posiibilities.size(); i++){
            cout << cur_posiibilities[i] << " \n"[i==5];
        }
        // cout << endl;
        // all_posibilities.push_back(cur_posiibilities);
        return;
    }

    for(ll i=idx; i<=n-6+size; i++){
        if (used[i] == 0){
            used[i] = 1;
            cur_posiibilities.push_back(arr[i]);
            search(i+1, size+1);
            used[i] = 0;
            cur_posiibilities.pop_back();
        }
    }
}

void solve(){
    arr.resize(0); cur_posiibilities.resize(0);
    // cout << n << endl;
    // all_posibilities.resize(0);
    used.assign(n, 0);
    for(ll i=0; i<n; i++){
        ll temp; cin>>temp;
        // cout << temp << ' ';
        arr.push_back(temp);
    }

    // for(ll num : arr){
    //     cout << num << ' ';
    // }

    // cout << endl;

    search(0,0);

    // for(ll i=0; i<all_posibilities.size(); i++){
    //     for(ll j=0; j<all_posibilities[i].size(); j++){
    //         cout << all_posibilities[i][j] << " \n"[j==all_posibilities[i].size()-1];
    //     }
    // }
    // cout << endl;

}

int main(){
    k=6;
    ll tc=1;
    while(cin>>n){
        if(n==0) break;
        if(tc != 1) cout << endl;
        solve();
        tc++;
    }
    // int tc; cin>>tc;
    // for(int i=0; i<tc; i++){
    //     cout << "Case #" << i+1 << ": ";
    //     solve();
    // }

    return 0;
}
