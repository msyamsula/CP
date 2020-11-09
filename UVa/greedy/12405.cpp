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
string field;

void solve(){
    cin>>n;
    cin>>field;
    ll end = -1, ans = 0;
    for(ll i=0; i<n; i++){
        if (i<=end) continue;
        if (field[i]=='#') continue;
        if (field[i] == '.'){
            end = i+2;
            ans++;
        }
        // cout << i << ' ' << end << endl;
    }

    cout << ans << endl;
}

int main(){
    int tc; cin>>tc;
    for(int i=0; i<tc; i++){
        cout << "Case " << i+1 << ": ";
        solve();
    }

    return 0;
}
