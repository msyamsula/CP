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

ll n,k;
vector<set<ll>> number_in_row, number_in_col;

vvl grid;
ll trace;
ll total;
vvl ans;

void search(ll i, ll j){
    // cout << i << ' ' << j << endl;
    if (total > 0) return;
    if (trace > k) return;
    if (i == n){
        if (trace == k){
            // for(vl a : grid){
            //     for(ll num : a){
            //         cout << num << ' ';
            //     }
            //     cout << endl;
            // }
            // cout << trace << endl;
            ans = grid;
            total++;
        }
        return;
    }

    for(ll num=1; num<=n; num++){
        if (number_in_row[i].find(num) != number_in_row[i].end()) continue;
        if (number_in_col[j].find(num) != number_in_col[j].end()) continue;
        grid[i][j] = num;
        number_in_row[i].insert(num);
        number_in_col[j].insert(num);
        if (i==j) trace += num;
        if (j+1<n) search(i, j+1);
        else search(i+1, 0);
        number_in_row[i].erase(num);
        number_in_col[j].erase(num);
        if (i==j) trace -= num;
    }
}

void solve(){
    cin>>n>>k;
    total = 0;
    // cout << n << endl;
    number_in_col.resize(0); number_in_col.resize(n);
    number_in_row.resize(0); number_in_row.resize(n);
    grid.resize(0); grid.assign(n, vl(n,-1));
    search(0,0);
    if (total == 0){
        cout << "IMPOSSIBLE" << endl;
        return;
    }

    cout << "POSSIBLE"<< endl;
    for(vl a : ans){
        for(ll i=0; i<a.size(); i++){
            cout << a[i] << " \n"[i==a.size()-1];
        }
    }

}

int main(){
    int tc; cin>>tc;
    for(int i=0; i<tc; i++){
        cout << "Case #" << i+1 << ": ";
        solve();
    }

    return 0;
}
