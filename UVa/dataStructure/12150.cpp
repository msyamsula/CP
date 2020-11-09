#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<long> vl;
typedef vector<vl> vvl;
typedef vector<string> vs;
typedef vector<vs> vvs;

void solve(long n){
    // cout << n << endl;
    vl startingGrid(n,-1);
    bool failed = 0;
    for(int i=0; i<n; i++){
        long num, gain; cin>>num>>gain;
        // cout << num << ' ' << gain << endl;
        long gridPos = i+gain;
        if (gridPos < 0 || gridPos >=n){
            // cout << -1 << endl; return;
            failed = 1;
        }

        if(startingGrid[gridPos] == -1) startingGrid[gridPos] = num;
        else {
            failed = 1;
        }
    }
    if (failed){
        cout << -1 << endl; 
        return;
    }

    for(int i=0; i<n; i++){
        cout << startingGrid[i] << " \n"[i==n-1];
    }
    // cout << endl;
}

int main(){
    long n;
    while(cin>>n){
        // cout << n << endl;
        if (n==0) break;
        // cout << "Case #" << i+1 << ": ";
        solve(n);
    }

    return 0;
}