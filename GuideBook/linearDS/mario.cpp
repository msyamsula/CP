#include<bits/stdc++.h>
using namespace std;

typedef map<char, int> mci;
typedef vector<int> vi;

void solve(int tc){
    int n; cin>>n;
    int prev; cin>>prev;
    if (n == 1){
        cout << "Case " << tc << ": " << 0 << ' ' << 0 << endl;
        return;
    }
    int h=0, l=0;
    // vi arr(n);
    int c;
    for (int i=1; i<n; i++){
        cin>>c;
        // cout << prev << ' ' << c << endl;
        if (c>prev) h++;
        else if (c<prev) l++;

        prev = c;
    }

    cout << "Case " << tc << ": " << h << ' ' << l << endl;


}

int main(){
    int tc; cin>>tc;
    for (int i=0; i<tc; i++){
        solve(i+1);
    }

    return 0;
}