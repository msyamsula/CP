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

vl arr, cur;
vvl all;
vvl status;

bool safe(ll row, ll col){
    for(ll i=0; i<8; i++){
        if(status[row][i] == 1) return 0;
    }

    for(ll i=0; i<8; i++){
        ll nrow = row+i, ncol = col+i;
        if (nrow>=8 || ncol >=8) break;
        if (status[nrow][ncol] == 1) return 0;
    }

    for(ll i=0; i<8; i++){
        ll nrow = row-i, ncol = col+i;
        if (nrow<0 || ncol >=8) break;
        if (status[nrow][ncol] == 1) return 0;
    }

    for(ll i=0; i<8; i++){
        ll nrow = row-i, ncol = col-i;
        if (nrow<0 || ncol <0) break;
        if (status[nrow][ncol] == 1) return 0;
    }

    for(ll i=0; i<8; i++){
        ll nrow = row+i, ncol = col-i;
        if (nrow>=8 || ncol <0) break;
        if (status[nrow][ncol] == 1) return 0;
    }

    return 1;
}


void search(ll col){
    if (col == 8){
        // for(ll num : cur){
        //     cout << num << ' ';
        // }
        // cout << endl;
        all.push_back(cur);
        return;
    }

    for(ll row=0; row<8; row++){
        if (safe(row, col)){
            status[row][col] = 1;
            cur.push_back(row+1);
            search(col+1);
            status[row][col] = 0;
            cur.pop_back();
        }
    }
}

void solve(){
    ll ans = MAXLL;
    for(ll i=0; i<all.size(); i++){
        ll cnt = 0;
        for(ll j=0; j<all[i].size(); j++){
            if (all[i][j] != arr[j]) cnt++;
        }
        ans = min(ans, cnt);
    }

    cout << ans << endl;
}

int main(){
    status.resize(0);
    status.assign(8, vl(8, 0));
    search(0);

    arr.assign(8, 0);
    ll tc=1;
    while(cin>>arr[0]){
        for(ll i=0; i<7; i++){
            cin>>arr[i+1];
        }
        cout << "Case " << tc << ": ";
        solve();
        tc++;
    }

    return 0;
}
