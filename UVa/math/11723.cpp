#include<bits/stdc++.h>
using namespace std;

void solve(int tc, int r, int n){

    if (r<=n || n == 0){
        cout << 0 << endl;
        return;
    }

    int ans = ceil(double(r-n)/n);
    if (ans > 26){
        cout << "impossible" << endl;
        return;
    }
    cout << ans << endl;
}

int main(){
    int r, n;
    int tc = 1;
    while(true){
        cin>>r>>n;
        if (r == 0 && n == 0) break;
        cout << "Case " << tc << ": ";
        solve(tc,r,n);
        tc++;
    }

    return 0;
}