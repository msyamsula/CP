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
vl dp;

ll calculate(ll num){
    ll cnt = 0;
    while(num > 0){
        ll temp = num;
        ll maxdigit = -1;
        while (temp>0){
            ll d = temp%10;
            maxdigit = max(d, maxdigit);
            temp /= 10;
        }
        num -= maxdigit;
        cnt++;
    }

    return cnt;
}

void solve(){
    cin>>n;
}

int main(){
    // solve();
    ll sz = 1000;
    dp.assign(sz+1, 0);
    for(ll i=0; i<=sz; i++){
        dp[i] = calculate(i);
    }

    for(ll num : dp){
        cout << num << ' ';
    }
    cout << endl;
    // cout << calculate(10) << endl;

    return 0;
}
