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

vvl table;
ll n;

void solve(){
    cin>>n;
    for(ll i=0; i<table[n].size(); i++){
        if (i!=0) cout << ' ';
        cout << table[n][i];
    }
    cout << endl;
}

int main(){
    table.assign(10000, vl(10, 0));
    for(ll i=1; i<=10000; i++){
        string num_str = to_string(i);
        table[i] = table[i-1];
        for(ll j=0; j<num_str.size(); j++){
            ll digit = num_str[j]-'0';
            table[i][digit]++;
        }
    }

    // for(vl a :table){
    //     for(ll num : a){
    //         cout << num << ' ';
    //     }
    //     cout << endl;
    // }

    int tc; cin>>tc;
    for(int i=0; i<tc; i++){
        // cout << "Case #" << i+1 << ": ";
        solve();
    }

    return 0;
}
