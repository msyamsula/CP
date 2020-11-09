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

ll t1,t2;
vvl price1, price2;
vl m;
vvl dp,parent;
deque<ll> choices;

void backtrack(ll u){
    if (u==0) return;
    ll C = t1+1;
    ll i = u/C, j = u%C;
    ll par = parent[i][j];
    // cout << u << ' ' << par << endl;
    ll pi = par/C, pj = par%C;
    choices.push_front(j-pj);
    backtrack(par);
}


void solve(){
    ll n; cin>>n;
    price1.resize(0); price2.resize(0); m.resize(0);
    price1.resize(n); price2.resize(n);
    for(ll i=0; i<n; i++){
        ll tot; cin>>tot;
        m.push_back(tot);
        price1[i].push_back(0); price2[i].push_back(0);
        for(ll j=0; j<tot; j++){
            ll p; cin>>p;
            price1[i].push_back(p);
        }
        for(ll j=0; j<tot; j++){
            ll p; cin>>p;
            price2[i].push_back(p);
        }
    }

    dp.resize(0); dp.assign(n+1, vl(t1+1, MAXLL));
    dp[0][0] = 0;
    parent.resize(0); parent.assign(n+1, vl(t1+1, -1));
    for(ll i=0; i<n; i++){
        for(ll j=0; j<t1+1; j++){
            if (dp[i][j] == MAXLL) continue;
            for (ll t=0; t<=m[i]; t++){
                if (j+t > t1) continue;
                if (dp[i][j]+price1[i][t]+price2[i][m[i]-t] < dp[i+1][j+t]){
                    dp[i+1][j+t] = dp[i][j]+price1[i][t]+price2[i][m[i]-t];
                    parent[i+1][j+t] = i*(t1+1)+j;
                }
            }
        }
    }

    // for(vl temp : dp){
    //     for(ll num : temp){
    //         cout << num << ' ';
    //     }
    //     cout << endl;
    // }
    // cout << endl;

    // for(vl temp : parent){
    //     for(ll num : temp){
    //         cout << num << ' ';
    //     }
    //     cout << endl;
    // }
    // cout << endl;

    ll ans = dp[n][t1];
    choices.resize(0);
    backtrack(n*(t1+1)+t1);

    cout << ans << endl;
    ll i=0;
    for(ll num : choices){
        cout << num << " \n"[i==choices.size()-1];
        i++;
    }
    // cout << endl;
}

int main(){
    // int tc; cin>>tc;
    // ll i=0;
    // while(cin>>t1>>t2){
    //     if (!t1 && !t2) break;
    //     // cout << "Case #" << i+1 << ": ";
    //     // if (i!=0) cout << endl;
    //     solve();
    //     cout << endl;
    //     // i++;
    // }
    ll num = (1ll<<61);
    num = (num-1)|num;
    cout << bitset<62>(2147483647) << endl;

    return 0;
}
