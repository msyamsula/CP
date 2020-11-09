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
vl piramid;

void solve(){
    cin>>n;
    // cout << "n: " << n << endl;
    ll tot = 0;
    while(n>0){
        auto it = upper_bound(piramid.begin(), piramid.end(), n);
        it--;
        if (*it == 0) break;
        // cout << "take: " << *it << endl;
        tot++;
        n -= *it;
        // cout << "n left: " << n << endl;
    }

    cout << tot << endl;
}

int main(){
    piramid.push_back(0);
    ll i=1;
    while(*piramid.rbegin() <= 1000000000){
        ll prev = *piramid.rbegin();
        ll cur = prev+2*i+i-1;
        piramid.push_back(cur);
        i++;
    }

    // for(ll num : piramid){
    //     cout << num << ' ';
    // }
    // cout << endl;
    // cout << piramid.size() << endl;
    int tc; cin>>tc;
    for(int i=0; i<tc; i++){
        // cout << "Case #" << i+1 << ": ";
        solve();
    }

    return 0;
}
