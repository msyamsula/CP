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
ll a, b;
void solve(){
    cin>>a>>b;
    if (a%2 == 0) a++;
    if (b%2 == 0) b--;
    if (a>b){
        cout << 0 << endl;
        return;
    }
    ll n = (b-a)/2;
    cout << (n+1)*(a+n) << endl;
}

int main(){
    int tc; cin>>tc;
    for(int i=0; i<tc; i++){
        cout << "Case " << i+1 << ": ";
        solve();
    }

    return 0;
}
