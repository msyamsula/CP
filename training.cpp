#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

bool comp(int i, int j){
    return i>j;
}

void solve(int tc){
    int n; cin>>n;
    int p; cin>>p;
    vi arr(n);
    vi presum(n+1, 0);
    for (int i=0; i<n; i++){
        cin>>arr[i];
    }

    sort(arr.begin(), arr.end(), comp);

    for(int i=0; i<n; i++){
        presum[i+1] = presum[i] + arr[i];
    }

    int mint = 1<<30;
    for (int i=0; i<n-p+1; i++){
        int t = p*arr[i] - (presum[i+p] - presum[i]);
        if (t<mint) mint = t;
    }

    cout << "Case #" << tc << ": " << mint << endl;
}

int main(){
    int tc; cin>>tc;
    for(int i=0; i<tc; i++){
        solve(i+1);
    }
    return 0;
}