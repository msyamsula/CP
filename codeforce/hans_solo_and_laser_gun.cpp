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

ll n,xo,yo;
vvl st;

void solve(){
    st.resize(0);
    cin>>n>>xo>>yo;
    for(ll i=0; i<n; i++){
        ll xi,yi; cin>>xi>>yi;
        st.push_back({xi,yi});
    }

    vl dead(n,0);
    ll ans = 0;
    for(ll i=0; i<n; i++){
        ll xi=st[i][0],yi=st[i][1];
        bool found = 0;
        if (xi == xo){
            for(ll j=0; j<n; j++){
                if (dead[j] == 1) continue;
                ll xj = st[j][0], yj = st[j][1];
                if (xj == xo){
                    dead[j]=1;
                    found = 1;
                }
            }
        } else {
            double m = double(yi-yo)/(xi-xo);
            double c = double(yi) - double(m*xi);
            for(ll j=0; j<n; j++){
                if (dead[j] == 1) continue;
                ll xj = st[j][0], yj = st[j][1];
                if (abs(double(yj)-double(m*xj+c)) < double(1)/1000000){
                    dead[j]=1;
                    found = 1;
                }
            }
        }

        if (found) ans++;
    }

    cout << ans << endl;
}

int main(){
    solve();
    // int tc; cin>>tc;
    // for(int i=0; i<tc; i++){
    //     cout << "Case #" << i+1 << ": ";
    // }

    return 0;
}
