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

double up;
ll m;
ll k;
vector<double> dp, paket;

void solve(){
    // cout << up << ' ' << m << endl;
    paket.resize(0); paket.assign(1000+1, MAXLL);
    paket[1] = up;
    for(ll i=0; i<m; i++){
        ll n; double price;
        cin>>n>>price;
        // cout << n << ' ' << price << endl;
        paket[n]=price;
    }

    string k_line;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin,k_line);
    // cout << k_line << endl;
    stringstream ss(k_line);
    ll k_temp;
    k = 0;
    vl k_arr;
    while(ss>>k_temp){
        // cout << k_temp << endl;
        k = max(k, k_temp);
        k_arr.push_back(k_temp);
    }
    // cout << k << endl;
    dp.resize(0); dp.assign(1000+1, 0);
    for(ll i=0; i<1000+1; i++){
        dp[i] = min(paket[1]*i, paket[i]);
        for(ll j=0; j<k_arr.size(); j++){
            ll tot_goods = i+k_arr[j];
            if (tot_goods > 1000) continue;
            dp[tot_goods] = min(dp[tot_goods], dp[i]+paket[k_arr[j]]);
        }
    }

    vector<double> minim_dp = dp;
    minim_dp[1000] = dp[1000];
    for(ll i=1000-1; i>=0; i--){
        minim_dp[i] = min(minim_dp[i+1], dp[i]);
    }

    for(double num : dp){
        cout << num << ' ';
    }
    cout << endl;

    for(double num : minim_dp){
        cout << num << ' ';
    }
    cout << endl;

    for(ll num : k_arr){
        cout << "Buy " << num << " for " << '$' << fixed << setprecision(2) << minim_dp[num] << endl;
    }
}

int main(){
    ll tc=1;
    while(cin>>up>>m){
        cout << "Case " << tc << ":" << endl;
        solve();
        tc++;
    }

    return 0;
}
