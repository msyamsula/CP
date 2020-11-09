#include<bits/stdc++.h>
using namespace std;
typedef vector<double> vi;

void solve(){
    long double n; cin>>n;
    long double a0, an1; cin>>a0>>an1;
    vi c(n+1);
    long double sigmacn = 0;
    long double sigma2nCn = 0;
    for(long double i=1;i<=n;i++){
        cin>>c[i];
        sigmacn+=c[i];
        sigma2nCn += 2*i*c[i];
    }

    long double an = a0+n*an1-sigma2nCn;
    an /= (n+1);
    long double a1 = a0-an+an1-2*sigmacn;

    // for(double num : c){
    //     cout << num << endl;
    // }
    // cout << endl;
    cout << setprecision(2) << fixed << a1 << endl;
}

int main(){
    int tc; cin>>tc;
    for(int i=0; i<tc; i++){
        if (i!=0) cout << endl;
        solve();
    }

    return 0;
}