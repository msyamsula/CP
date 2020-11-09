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
    for(ll i=0; i<n; i++){
        ll temp; cin>>temp;
        arr.push_back(temp);
    }

    vvl grid;
    vl row;
    for (ll i=0; i<n; i++){
        if (row.size()==0) row.push_back(arr[i]);
        else{
            if (arr[i]>(*row.rbegin())) row.push_back(arr[i]);
            else {
                grid.push_back(row);
                row.resize(0);
                row.push_back(arr[i]);
            }
        }
    }
    grid.push_back(row);

    cout << "grid: " << endl;
    for(vl a : grid){
        for(ll num : a){
            cout << num << ' ';
        }
        cout << endl;
    }

    // cout << "total grid: " << grid.size() << endl;
    ll prev = -MAXLL;
    for(ll i=0; i<grid.size(); i++){
        auto it = lower_bound(grid[i].begin(), grid[i].end(), prev);
        if (it == grid[i].end()){
            cout << "NO" << endl;
            return;
        }
        cout << "grid " << i << ": " << *it << endl;
        if (i>0) prev = min(prev, *it);
        else prev = *it;
    }

    cout << "YES" << endl;

    // string ans = (arr.size() == 1) ? "YES" : "NO";

    // cout << ans << endl;
}

int main(){
    int tc; cin>>tc;
    for(int i=0; i<tc; i++){
        // cout << "Case #" << i+1 << ": ";
        solve();
    }

    return 0;
}
