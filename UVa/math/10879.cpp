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
ll k;
void solve(){
    cin>>k;
    cout << k << " = ";
    vl factor;
    for(ll i=2; i*i <= k; i++){
        if (k%i == 0) factor.push_back(i);
        if (factor.size() == 2) break;
    }

    cout << factor[0] << " * " << k/factor[0] << " = " << factor[1] << " * " << k/factor[1] << endl;
}

int main(){
    int tc; cin>>tc;
    for(int i=0; i<tc; i++){
        cout << "Case #" << i+1 << ": ";
        solve();
    }

    return 0;
}
