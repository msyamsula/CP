#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

void solve(int tc){
    int n;cin>>n;
    vi arr(n);
    int hi = 0;
    cout << "Case #" << tc << ':';
    for(int i=0; i<n; i++){
        cin>>arr[i];
        int limit = hi+1;
        int count = 0;
        for(int j=0; j<=i; j++){
            if (arr[j] >= limit) count++;
        }
        hi = max(hi,count);
        cout << ' ' << hi;
        // hi = max(limit, count);
    }
    cout << endl;
}

int main(){
    int tc; cin>>tc;
    for(int i=0; i<tc; i++){
        solve(i+1);
    }

    return 0;
}