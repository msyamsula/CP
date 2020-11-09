#include<bits/stdc++.h>
// #include<iostream>
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

void solve(){

}

int main(){
    // int tc; cin>>tc;
    // for(int i=0; i<tc; i++){
    //     cout << "Case #" << i+1 << ": ";
    //     solve();
    // }
    ll a; cin>>a;
    a-=2;
    if (a<=0 || a%2 != 0) cout << "NO" << endl;
    else cout << "YES" << endl;
    return 0;
}
