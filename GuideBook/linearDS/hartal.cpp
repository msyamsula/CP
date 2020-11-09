#include<bits/stdc++.h>
using namespace std;

typedef map<int, int> mii;
typedef vector<int> vi;

void solve(){
    int n; cin>>n;
    int p; cin>>p;
    vi arr(p);
    for (int i=0; i<p; i++){
        cin >> arr[i];
    }

    int count = 0;
    for (int i=1; i<=n; i++){
        for (int j=0; j<p; j++){
            if (i%7 == 6 || i%7==0) continue;
            if (i%arr[j] == 0){
                // cout << i << ' ' << arr[j] << endl;
                count++;
                break;
            }
        }
    }

    cout << count << endl;
    

}

int main(){
    int tc; cin>>tc;
    for (int i=0; i<tc; i++){
        solve();
    }

    return 0;
}