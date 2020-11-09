#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;

void solve(int tc){
    int ans = 0;
    int n; cin>>n;
    vi arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    for(int i=1; i<n-1; i++){
        if (arr[i] > arr[i-1] && arr[i] > arr[i+1]) ans++;
    }

    cout << "Case #" << tc << ": " << ans << endl;
}

int main(){
    int tc; cin>>tc;
    for(int i=0;i<tc; i++){
        solve(i+1);
    }

    return 0;
}