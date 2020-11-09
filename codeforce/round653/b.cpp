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

ll divide(ll &n, ll a){
    ll ans = 0;
    while(n%a==0){
        n/=a;
        ans++;
    }

    return ans;
}

void solve(){
    cin>>n;
    ll two = divide(n,2);
    ll three = divide(n,3);
    if (n!=1 || two>three){
        cout << -1 << endl;
        return;
    }

    cout << three-two+three << endl;

}

int main(){
    int tc; cin>>tc;
    for(int i=0; i<tc; i++){
        // cout << "Case #" << i+1 << ": ";
        solve();
    }

    return 0;
}
