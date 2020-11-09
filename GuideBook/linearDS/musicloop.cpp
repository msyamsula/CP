#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

void solve(int n){
    vi arr(n);
    for (int i=0; i<n; i++){
        cin>>arr[i];
    }

    int count = 0;
    for (int i=0; i<n; i++){
        int left = (i==0) ? arr[n-1] : arr[i-1];
        int right = (i==n-1) ? arr[0] : arr[i+1];

        if ( left <= arr[i] && arr[i] <= right) continue;
        if ( left >= arr[i] && arr[i] >= right) continue;

        count++;
    }

    cout << count << endl;
}

int main(){
    int n;
    while(cin>>n){
        if (n == 0) break;
        solve(n);
    }

    return 0;
}