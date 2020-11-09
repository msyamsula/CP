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
vl visitor;

void solve(){
    cin>>n;
    visitor.resize(0);
    for(ll i=0; i<n; i++){
        ll temp; cin>>temp;
        visitor.push_back(temp);
    }

    ll record = -MAXLL;
    ll cnt = 0;
    for(ll i=0; i<n; i++){
        if (visitor[i]>record){
            if (i==n-1){
                cnt++;
                // cout << i+1 << endl;
            }
            else if (visitor[i+1] < visitor[i]){
                cnt++;
                // cout << i+1 << endl;
            }
        }
        record = max(record, visitor[i]);
    }

    // cout << "cnt: " 
    cout << cnt << endl;
}

int main(){
    int tc; cin>>tc;
    for(int i=0; i<tc; i++){
        cout << "Case #" << i+1 << ": ";
        solve();
    }

    return 0;
}
