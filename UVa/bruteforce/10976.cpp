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

void solve(ll k){
    ll x=MAXLL,y=-MAXLL;
    vs ans;
    for(ll d=1; x>=y; d++){
        double xt=double(k*(k+d))/d, yt = k+d;
        x = k*(k+d)/d, y = k+d;
        if (xt == x) ans.push_back("1/" + to_string(k) + " = " + "1/" + to_string(x) + " + " + "1/" + to_string(y));
    }

    cout << ans.size() << endl;
    for(string temp : ans){
        cout << temp << endl;
    }
}

int main(){
    // int tc; cin>>tc;
    // for(int i=0; i<tc; i++){
    //     cout << "Case #" << i+1 << ": ";
    //     solve();
    // }
    ll k;
    while(cin>>k){
        solve(k);
    }

    return 0;
}
