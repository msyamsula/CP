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

ll o,z;

void solve(){
    cin>>z>>o;
    ll n=z+o;
    // cout << z << ' ' << o << endl;
    // cout << (z-1 <= o) << endl;
    // cout << (o<=2*(z+1)) << endl;
    if (z-1 <= o && o <= 2*(z+1)){
        string ans = "";
        if (z>=o){
            for(ll i=0; i<(z+o); i++){
                if (i%2 == 0) ans += '0';
                else ans += '1';
            }
            cout << ans << endl;
            return;
        } else {
            ans.resize(0); ans.assign(2*(z+1)+z, '.');
            for(ll i=0; i<z; i++){
                ll idx = i*3+2;
                ans[idx] = '0';
            }
            // cout << o << endl;
            ll limit = o;
            for(ll i=0; i<limit; i++){
                ll idx = i*3+0;
                if (idx>=(2*(z+1)+z)) break;
                ans[idx] = '1';
                o--;
            }
            // cout << o << endl;
            limit = o;
            for(ll i=0; i<limit; i++){
                ll idx = i*3+1;
                if (idx>=(2*(z+1)+z)) break;
                ans[idx] = '1';
                o--;
            }

            string temp = "";
            for(char c:ans){
                if (c != '.') temp+=c;
            }

            cout << temp << endl;
            return;
        }
    }

    cout << -1 << endl;
}

int main(){
    solve();
    // int tc; cin>>tc;
    // for(int i=0; i<tc; i++){
    //     cout << "Case #" << i+1 << ": ";
    // }

    return 0;
}
