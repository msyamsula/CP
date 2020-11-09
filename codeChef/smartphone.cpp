#include<bits/stdc++.h>
using namespace std;

typedef vector<long> vi;

// int bs(int a, int b, vi arr){
//     if (a == b) return arr[a];
//     int mid = (a+b)/2;
//     if (arr[mid]>=2) return bs(a,mid,arr);
//     return bs(mid+1,b,arr);
// }

int main(){
    int n; cin>>n;
    vi arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    sort(arr.begin(), arr.end());

    long ans = -pow(2,62);
    // cout << ans << endl;
    for(int i=0; i<n; i++){
        long lb = arr[i];
        vi::iterator it = lower_bound(arr.begin(), arr.end(),lb);
        int idx = it-arr.begin();
        // cout << i << ' ' << idx << endl;
        ans = max(ans, (n-idx)*lb);
    }

    cout << ans << endl;
    return 0;
}