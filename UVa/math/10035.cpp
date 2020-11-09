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

string a, b;

void solve(){
    string arev,brev;
    ll n = a.size();
    for(ll i=0; i<a.size(); i++){
        arev += a[n-1-i];
    }

    n = b.size();
    for(ll i=0; i<b.size(); i++){
        brev += b[n-1-i];
    }


    ll carry = 0;
    ll ans = 0;
    for(ll i=0; i<max(arev.size(), brev.size()); i++){
        ll d1 = (i<arev.size()) ? arev[i]-'0' : 0;
        ll d2 = (i<brev.size()) ? brev[i]-'0' : 0;
        ll next = carry+d1+d2;
        carry = next/10;
        if (carry) ans++;
        next = next%10;
    }

    if (!ans){
        cout << "No carry operation." << endl;
        return;
    }

    if (ans == 1){
        cout << ans << " carry operation." << endl;
        return;
    }

    cout << ans << " carry operations." << endl;
}

int main(){
    while(cin>>a>>b){
        if (a=="0" && b=="0") break;
        solve();
    }

    return 0;
}
