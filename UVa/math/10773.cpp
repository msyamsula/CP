#include<bits/stdc++.h>
using namespace std;

void solve(){
    int d,v,u; cin>>d>>v>>u;
    if (v>=u || v == 0){
        cout << "can't determine" << endl;
        return;
    }

    double y = pow( (u*u-v*v), 0.5 );
    double num = d*(u-y);
    double den = y*u;

    cout << fixed << setprecision(3) << num/den << endl;
}

int main(){
    int tc; cin>>tc;
    for(int i=0; i<tc; i++){
        cout << "Case " << i+1 << ": ";
        solve();
    }

    return 0;
}