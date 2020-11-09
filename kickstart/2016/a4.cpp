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

struct card{
    vl add,cost;
};

vector<card> arr;
vvl dp;

void solve(){
    arr.resize(0);
    ll m,n; cin>>m>>n;
    ll ai=0;
    for(ll i=0; i<n; i++){
        ll ml, cl; cin>>ml>>cl;
        cl--;
        vl attack, cost;
        for(ll j=0; j<ml; j++){
            ll num; cin>>num;
            attack.push_back(num);
        }
        ai+=attack[cl];

        for(ll j=0; j<ml-1; j++){
            ll num; cin>>num;
            cost.push_back(num);
        }

        vl pay; pay.assign(ml-cl,0);
        for(ll i=cl; i<ml-1; i++){
            pay[i+1]=pay[i]+cost[i];
        }

        vl at;
        for(ll i=cl; i<ml; i++){
            at.push_back(attack[i]-attack[cl]);
        }
        card cc; cc.add=at; cc.cost=pay;
        arr.push_back(cc);
    }

    cout << "tes" << endl;
    for(card temp : arr){
        for(ll i=0; i<temp.add.size(); i++){
            cout << temp.add[i] << " \n"[i==temp.add.size()-1];
        }

        for(ll i=0; i<temp.add.size(); i++){
            cout << temp.cost[i] << " \n"[i==temp.add.size()-1];
        }
        cout << endl;

    }
    dp.resize(0); dp.assign(n+1, vl(m+1, -MAXLL));
    dp[0][0]=0;
    for(ll i=0; i<n; i++){
        for(ll j=0; j<=m; j++){
            if(dp[i][j] == -MAXLL) continue;
            for(ll ii=0; ii<arr[i].add.size(); ii++){
                ll nj=j+arr[i].cost[ii];
                if (nj>m) continue;
                dp[i+1][nj] = max(dp[i+1][nj], dp[i][j] + arr[i].add[ii]);
            }
        }
    }

    // for(vl temp: dp){
    //     for(ll num : temp){
    //         cout << num << ' ';
    //     }
    //     cout << endl;
    // }

    ll ans = -MAXLL;
    for(ll i=0; i<=m; i++){
        ans = max(ans, dp[n][i]);
    }
    cout << ans+ai << endl;

}

int main(){
    int tc; cin>>tc;
    for(int i=0; i<tc; i++){
        cout << "Case #" << i+1 << ": ";
        solve();
    }

    return 0;
}
