#include<bits/stdc++.h>
using namespace std;

void solve(){
    int a, b, p;
    cin>>a>>b>>p;
    int ans = double( (2*a-b)*p )/(a+b);
    // double ans = floor((fraction-1)*p);
    // cout << fraction << ' ' << (fraction-1)*3 << endl;
    cout << ans << endl;
}

int main(){
    int tc; cin>>tc;
    for(int i=0; i<tc; i++){
        solve();
    }

    return 0;
}