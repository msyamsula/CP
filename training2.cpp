#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

void solve(int tc){
    int n,p;
    cin>>n>>p;
    vi arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    sort(arr.begin(), arr.end());

    vi ps(n+1,0);
    for(int i=0; i<n+1; i++){
        ps[i+1] = ps[i] + arr[i];
    }

    int s_idx = 0;
    int min = 1<<30, ans = min;
    for (int i=0; i<n-p+1; i++){
        if (arr[i+p-1]-arr[i] <= min){
            int target = arr[i+p-1];
            int total_hour = p*target - ps[i+p] + ps[i];
            // for(int j=i; j<=i+p-1; j++){
            //     total_hour+=target-arr[j];
            // }
            if (total_hour < ans) ans = total_hour;
        }
    }

    cout << "Case #" << tc << ": " << ans << endl;
}

int main(){
    int tc; cin>>tc;
    for(int i=0; i<tc; i++){
        solve(i+1);
    }

    return 0;
}