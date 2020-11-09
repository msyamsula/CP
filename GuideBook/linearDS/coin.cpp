#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

void solve(int tc, string blank){
    if (tc!=1) cout << endl;
    int n, w;
    cin >> n; cin >> w;
    vi fraud(n+1, 1);
    // cout << n << ' ' << w << endl;
    cin.ignore ( numeric_limits<streamsize>::max(), '\n' );
    for (int i=0; i<w; i++){
        string line1, line2;
        getline(cin, line1);
        getline(cin, line2);
        // cout << "line2 " << line2 << endl;
        if (line2 == "="){
            stringstream ss(line1);
            int ii=0, temp;
            while(ss>>temp){
                // cout << ii << ' ' << temp << endl;
                if (ii==0){
                    ii++;
                    continue;
                }
                fraud[temp] = 0;
                ii++;
            }
        }
    }

    int tot = 0, ans;
    for (int i=1; i<n+1; i++){
        // cout << i << ' ' << fraud[i] << endl;
        if (fraud[i] == 1){
            ans = i;
            tot++;
        }

        if (tot > 1){
            cout << 0 << endl;
            return;
        }
    }

    cout << ans << endl;
}

int main(){
    int tc; cin>>tc;
    cin.ignore ( numeric_limits<streamsize>::max(), '\n' );
    for (int i=1; i<=tc; i++){
        // cout << i << endl;  
        string blank;
        getline(cin, blank);
        // cout << blank << endl;
        solve(i, blank);
    }

    return 0;
}