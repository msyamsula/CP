#include<bits/stdc++.h>
using namespace std;

long long bs(long a, long b, long n){
    // cout << a << ' ' << b << endl;
    long long mid = (a+b)/2;
    bool test1 = (mid*mid+mid-2*n < 0);
    bool test2 = (mid*mid+mid-2*n > 0);
    if (a>b){
        return b;
    }

    if (test1){
        return bs(mid+1,b,n);
    } else if (test2) {
        return bs(a,mid-1,n);
    } else {
        return mid;
    }
}

void solve(){
    long long n; cin>>n;
    if (n==0){
        cout << n << endl;
        return;
    }
    // long long a = 1;
    // // n = pow(n,0.5);
    // long long ans = bs(a,n,n);
    // cout << ans << endl;
    long long a = 1, r = 1;
    while(a<n){
        a += r+1;
        r += (a<=n) ? 1 : 0;
    }

    cout << r << endl;
}

int main(){
    int tc; cin>>tc;
    for (int i=0; i<tc; i++){
        solve();
    }

    return 0;
}