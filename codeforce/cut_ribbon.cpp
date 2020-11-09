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

ll n,a,b,c;

void solve(){
    cin>>n>>a>>b>>c;
    vl target; target.assign(n+1, 0);
    target[n]=1;
    vl dp; dp.assign(n+1, 0);
    dp[0]=1;
    ll tot=0, ans = -MAXLL;
    while(1){
        // for(ll num: dp){
        //     cout << num << ' ';
        // }
        // cout << endl;
        vl copy(n+1, 0);
        for(ll i=0; i<=n; i++){
            if (dp[i]){
                if(i+a<=n) copy[i+a] = 1;
                if (i+b<=n) copy[i+b] = 1;
                if (i+c<=n) copy[i+c] = 1;
            }
        }
        dp = copy;
        vl zonk(n+1, 0);
        if (dp == zonk) break;
        tot++;
        if (dp[n] == 1) ans = max(ans, tot);
        // if (tot == 2) break;
    }
    // for(ll num: dp){
    //     cout << num << ' ';
    // }
    // cout << endl;

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
