#include<bits/stdc++.h>
using namespace std;

typedef vector<long> vi;

long cek(long left, long right, vi &arr, long m){
    if (left > right) return -1;
    if (left == right) return right;
    long n = arr.size();
    long mid = (left+right)/2;
    if (mid == left){
        long cm2=0;
        for(long i=0; i<n; i++){
            cm2 += arr[i]^right;
        }
        if (cm2 > m) return left;
        return right;
    }
    cout << ' ' << left << ' ' << mid << ' ' << right <<endl;
    long cm=0;
    for(long i=0; i<n; i++){
        cm += arr[i]^mid;
    }

    if (cm > m) return cek(left,mid-1,arr,m);
    return cek(mid,right,arr,m);
}

void solve(){
    long n,m; cin>>n>>m;
    vi arr(n);
    for(long i=0; i<n; i++){
        cin>>arr[i];
    }

    // long cm=0;
    // for(long i=0; i<n; i++){
    //     cm += arr[i]^m;
    // }

    // if (cm <= m){
    //     cout << m << endl;
    //     return;
    // }

    long right = pow(10,18), left = 0;
    cout << right << endl;
    long ans = cek(left,right,arr,m);
    cout << ans << endl;
}


int main(){
    int tc; cin>>tc;
    for(int i=0; i<tc; i++){
        solve();
    }

    return 0;
}