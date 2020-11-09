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

ll n,m;
vl dragon, knight;

void solve(){
    dragon.resize(0); knight.resize(0);
    for(ll i=0; i<n; i++){
        ll temp; cin>>temp;
        dragon.push_back(temp);
    }

    for(ll i=0; i<m; i++){
        ll temp; cin>>temp;
        knight.push_back(temp);
    }

    sort(dragon.begin(), dragon.end());
    sort(knight.begin(), knight.end());

    // cout << "dragon :";
    // for(ll num : dragon){
    //     cout << num << ' ';
    // }
    // cout << endl;

    // cout << "knight :";
    // for(ll num : knight){
    //     cout << num << ' ';
    // }
    // cout << endl;

    ll k=0;
    ll pay=0;
    for(ll d=0; d<n; d++){
        while(knight[k]<dragon[d] && k<m) k++;
        if (k==m){
            cout << "Loowater is doomed!" << endl;
            return;
        }
        pay+=knight[k];
        k++;
    }

    cout << pay << endl;
}

int main(){
    while(cin>>n>>m){
        if(!n && !m) break;
        solve();
    }
    // int tc; cin>>tc;
    // for(int i=0; i<tc; i++){
    //     cout << "Case #" << i+1 << ": ";
    //     solve();
    // }

    return 0;
}
