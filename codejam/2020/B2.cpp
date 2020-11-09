#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;

void solve(){
    long comp = pow(10,9);
    for(int i=-5; i<=5; i++){
        for(int j=-5; j<=5; j++){
            cout << j << ' ' << i << endl << flush;
            string output; cin>>output;
            if(output == "CENTER"){
                return;
            }
        }
    }

    cout << pow(10,9)+200 << ' ' << pow(10,9)+200 << endl;
    string output; cin>>output;
    if(output == "WRONG") return;

}

int main(){
    int tc; cin>>tc;
    long a,b; cin>>a>>b;
    for(int i=0; i<tc; i++){
        // cout << "Case #" << i+1 << ": ";
        solve();
    }

    return 0;
}