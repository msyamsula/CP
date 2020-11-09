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

ll f91(ll a){
    // cout << a << endl;
    if (a<=0) return a;
    if (a<=100) return f91(f91(a+11));
    else if (a>=101) return a-10;
    return 0;
}

void solve(){
    cout << "f91(" << n << ") = " << f91(n) << endl;
    // cout << endl;
}

int main(){
    while(cin>>n){
        if (!n) break;
        solve();
    }

    return 0;
}
