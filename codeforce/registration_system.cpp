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
map<string, ll> db;

void solve(){
    cin>>n;
    for(ll i=0; i<n; i++){
        string s; cin>>s;
        if (db.find(s)==db.end()){
            cout << "OK" << endl;
            db[s]++;
        } else {
            ll version = db.at(s);
            string alt = s+to_string(version);
            cout << alt << endl;
            db[s]++;
        }
    }
}

int main(){
    solve();
    // int tc; cin>>tc;
    // for(int i=0; i<tc; i++){
    //     cout << "Case #" << i+1 << ": ";
    // }

    return 0;
}
