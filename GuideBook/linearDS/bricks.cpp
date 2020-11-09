#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

void solve(int tc, int n){
    vi ch(n); int sum = 0;
    for (int i=0; i<n; i++){
        cin>>ch[i];
        sum+=ch[i];
    }

    int avg = sum/n, ans = 0;
    for (int i=0; i<n; i++){
        ans += max(0, ch[i]-avg);
    }

    cout << "Set #" << tc << endl;
    cout << "The minimum number of moves is " << ans << "." << endl << endl;
}

int main(){
    int n, tc = 1;
    while(cin>>n){
        if (n == 0) break;
        solve(tc, n);
        tc++;
    }

    return 0;
}