#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

void solve(int tc){
    int n,k,p;
    cin>>n>>k>>p;
    vi arr(n,0);
    vi fixed(n,0);
    int unfixed = n;
    for (int i=0; i<k; i++){
        int a,b,c;
        cin>>a>>b>>c;
        arr[a-1] = c;
        fixed[a-1] = 1;
        unfixed--;
    }

    bitset<64> a = p-1;

    // cout << a << endl;

    string ans = "";
    for (int i=n-1; i>=0; i--){
        if (fixed[i] == 1){
            // cout << i << " fixed" <<endl; 
            ans = to_string(arr[i]) + ans;
        } else {
            // cout << i << " unfixed" <<endl; 
            ans = to_string(a[0]) + ans;
            a = a>>1;
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