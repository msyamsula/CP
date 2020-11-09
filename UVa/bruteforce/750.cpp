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

ll N,r,c;
vl cur_ans;
vvl all;
ll sz=8;
vvl status;

bool safe(ll row, ll col){
    for(ll i=0; i<sz; i++){
        if(status[row][i] == 1) return 0;
    }

    for(ll i=1; i<sz; i++){
        ll nrow = row+i, ncol = col+i;
        if (nrow>=sz || ncol >= sz) break;
        if (status[nrow][ncol] == 1) return 0;
    }

    for(ll i=1; i<sz; i++){
        ll nrow = row-i, ncol = col+i;
        if (nrow<0 || ncol >= sz) break;
        if (status[nrow][ncol] == 1) return 0;
    }

    for(ll i=1; i<sz; i++){
        ll nrow = row-i, ncol = col-i;
        if (nrow<0 || ncol < 0) break;
        if (status[nrow][ncol] == 1) return 0;
    }

    for(ll i=1; i<sz; i++){
        ll nrow = row+i, ncol = col-i;
        if (nrow>=sz || ncol < 0) break;
        if (status[nrow][ncol] == 1) return 0;
    }

    return 1;
}

void search(ll col){
    if (col == 8){
        // for(vl temp : status){
        //     for(ll num : temp){
        //         cout << num << ' ';
        //     }
        //     cout << endl;
        // }
        // cout << endl;
        all.push_back(cur_ans);
        return;
    }

    for(ll row=0; row<sz; row++){
        if (safe(row,col)){
            cur_ans.push_back(row);
            status[row][col] = 1;
            search(col+1);
            cur_ans.pop_back();
            status[row][col] = 0;
        }
    }
}

void solve(){
    cout << "SOLN";
    for(ll i=0; i<7; i++){
        cout << ' ';
    }
    cout << "COLUMN" << endl;
    cout << " #";
    for(ll i=0; i<5; i++){
        cout << ' ';
    }
    for(ll i=0; i<8; i++){
        cout << ' ' << i+1;
    }
    cout << endl << endl;

    cin>>r>>c;
    r--;c--;
    vvl ans;
    for(ll i=0; i<all.size(); i++){
        for(ll j=0; j<all[i].size(); j++){
            ll row = all[i][j], col = j;
            if (row == r && col == c) ans.push_back(all[i]);
        }
    }

    for(ll i=0; i<ans.size(); i++){
        cout << setw(2) << i+1;
        for(ll i=0; i<5; i++){
            cout << ' ';
        }
        for(ll j=0; j<ans[i].size(); j++){
            cout << ' ' << ans[i][j]+1;
        }
        cout << endl;
    }
}

int main(){
    all.resize(0); cur_ans.resize(0);
    status.resize(0); status.assign(sz, vl(sz, 0));
    search(0);
    // cout << all.size() << endl;
    // for(vl temp : all){
    //     for(ll num : temp){
    //         cout << num << ' ';
    //     }
    //     cout << endl;
    // }
    int tc; cin>>tc;
    for(int i=0; i<tc; i++){
        if (i!=0) cout << endl;
        // cout << "Case #" << i+1 << ": ";
        solve();
    }

    return 0;
}
