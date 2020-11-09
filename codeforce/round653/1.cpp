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

ll x,y,n;

void solve(){
    cin>>x>>y>>n;
    ll row = floor((double)(n-y)/x);
    ll k = row*x+y;
    cout << k << endl;
}

int main(){
    // int tc; cin>>tc;
    // for(int i=0; i<tc; i++){
    //     // cout << "Case #" << i+1 << ": ";
    //     solve();
    // }

    cout << (15116544ll%6) << endl;
    cout << double(log(15116544)/log(6)) << endl;

    return 0;
}
