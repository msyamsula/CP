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

ll n, q;
vl kunci;
// vl order;
// map<vl, vl> dp;
// vl order;

vl open(ll le, ll ri, ll room){
    // cout << le << ' ' << ri << endl;
    // if (dp.find({le,ri}) != dp.end()){
    //     // cout << "memo" << endl;
    //     return dp[{le,ri}];
    // };

    // cout << "calculate" << endl;
    if (kunci[le] == 0 && kunci[ri] == 0) return {};

    if (kunci[le] !=0 && kunci[ri] != 0){
        if (kunci[le] < kunci[ri]){
            vl memo = open(le-1,ri,le-1);
            memo.insert(memo.begin(), le-1);
            // return dp[{le,ri}] = memo;
            return memo;
        }

        vl memo = open(le, ri+1, ri);
        memo.insert( memo.begin(), ri);
        // return dp[{le,ri}] = memo;
        return memo;
    }

    if (kunci[le] == 0){
        vl memo = open(le, ri+1, ri);
        memo.insert( memo.begin(), ri);
        // return dp[{le,ri}] = memo;
        return memo;
    }

    vl memo = open(le-1,ri,le-1);
    memo.insert(memo.begin(), le-1);
    // return dp[{le,ri}] = memo;
    return memo;
    // if (kunci[ri] == 0){
    // }
    
}

void solve(){
    cin>>n>>q;
    // dp.clear();
    kunci.resize(0);
    for(ll i=0; i<n-1; i++){
        ll temp; cin>>temp;
        kunci.push_back(temp);
    }

    kunci.insert(kunci.begin(), 0);
    kunci.push_back(0);
    // cout << "kunci: ";
    // for (ll num : kunci){
    //     cout << num << ' ';
    // }
    // cout << endl;
    
    vvl table; table.resize(n);
    for(ll i=0; i<n; i++){
        vl order = open(i, i+1, i);
        order.insert(order.begin(), i);
        table[i] = order;
    }
    // cout << le << ' ' << ri << endl;
    // cout << kunci[le] << ' ' << kunci[ri] << endl;
    // order.resize(0);
    // order.push_back(start+1);
    // order.insert(order.begin(), start)    
    // order.insert(order.end(), memo.begin(), memo.end());

    // for (ll num : order){
    //     cout << num+1 << ' ';
    // }
    // cout << endl;

    // cout << "table: " << endl;
    // for(vl arr : table){
    //     for(ll num : arr){
    //         cout << num+1 << ' ';
    //     }
    //     cout << endl;
    // }
    // cout << endl;

    // cout << "dp: " << endl;
    // for(pair<vl, vl> p : dp){
    //     cout << "key : ";
    //     for(ll num : p.first){
    //         cout << num << ' ';
    //     }
    //     cout << endl;

    //     cout << "value : ";
    //     for(ll num : p.second){
    //         cout << num << ' ';
    //     }
    //     cout << endl;
    // }

    for(ll i=0; i<q; i++){
        ll room, index;
        cin>>room>>index;
        room--; index--;
        cout << ' ' << table[room][index]+1;
    }
    cout << endl;
}

int main(){
    int tc; cin>>tc;
    for(int i=0; i<tc; i++){
        cout << "Case #" << i+1 << ":";
        solve();
    }

    return 0;
}
