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

string num;

void solve(){
    cin >> num;
    ll n = num.size();
    ll max_digit = -MAXLL;
    for(ll i=0; i<n; i++){
        max_digit = max(max_digit, (ll)num[i]-'0');
    }
    vl arr(max_digit, 0);
    for(ll i=0; i<n; i++){
        ll power = n-1-i;
        ll cur = pow(10, power);
        ll upper = (ll)num[i]-'0';
        for(ll j=0; j<upper; j++){
            arr[j] += cur;
        }
    }

    cout << max_digit << endl;
    for(ll i=0; i<max_digit; i++){
        if (i!=0) cout << ' ';
        cout << arr[i];
    }
    cout << endl;

}

int main(){
    solve();
    // int tc; cin>>tc;
    // for(int i=0; i<tc; i++){
    //     cout << "Case #" << i+1 << ": ";
    // }

    return 0;
}
