#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

void solve(int tc){
    int n,k; cin>>n>>k;
    vi session(n,0);
    vi diff(n,0);
    for(int i=0; i<n; i++){
        cin>>session[i];
        if (i>0){
            diff[i] = abs(session[i] - session[i-1]);
        }
    }

    sort(diff.begin(), diff.end());
    // for(int i=0; i<diff.size(); i++){
    //     cout << diff[i] << ' ';
    // }
    // cout << endl;
    int ans = max(ceil(double(diff[n-1])/2), double(diff[n-2]));
    cout << "Case #" << tc << ": " << ans << endl;
}

int main(){
    int tc; cin>>tc;
    for(int i=0; i<tc; i++){
        solve(i+1);
    }

    return 0;
}