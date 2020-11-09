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

void solve(){
    vl pd;
    ll sum = 0;
    for(ll i=1; i<=abs(n); i++){
        if (n%i == 0){
            ll b = i;
            ll c = n/i;
            if (c == -1 && c == 1) continue;
            if (b != n) sum+=b;
        }
    }

    if (sum == n){
        cout << setw(5) << n << "  " << "PERFECT" << endl;
        return;
    } else if (sum < n){
        cout << setw(5) << n << "  " << "DEFICIENT" << endl;
        return;
    }

    cout << setw(5) << n << "  " << "ABUNDANT" << endl;
}

int main(){
    cout << "PERFECTION OUTPUT" << endl;
    while(cin>>n){
        if (!n) break;
        solve();
    }
    cout << "END OF OUTPUT" << endl;

    return 0;
}
