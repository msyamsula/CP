#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<long> vl;
typedef vector<vl> vvl;
typedef vector<string> vs;
typedef vector<vs> vvs;

vvi mat;

void solve(int n){
    // cout << "n :";
    // cout << n << endl;
    mat.resize(0);
    mat.assign(n, vi(n, 0));
    vi srow(n,0);
    vi scol(n,0);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>mat[i][j];
            srow[i] += mat[i][j];
            scol[j] += mat[i][j];
        }
    }

    // for(vi temp: mat){
    //     for(int a : temp){
    //         cout << a << ' ';
    //     }
    //     cout << endl;
    // }

    vi oddrow;
    for(int i=0; i<n; i++){
        // cout << srow[i] << ' ';
        int s = srow[i];
        if (s%2 != 0) oddrow.push_back(i);
    }
    // cout << endl;

    vi oddcol;
    for(int i=0; i<n; i++){
        int s = scol[i];
        if (s%2 != 0) oddcol.push_back(i);
        // cout << s << ' ';
    }
    // cout << endl;

    if (oddrow.empty() && oddcol.empty()){
        cout << "OK" << endl;
        return;
    } else if (oddrow.size()==1 && oddcol.size()==1){
        cout << "Change bit (" << oddrow[0]+1 << ',' << oddcol[0]+1 << ')' << endl;
        return; 
    }

    cout << "Corrupt" << endl;

}

int main(){
    int n;
    while(cin>>n){
        if (n==0) break;
        solve(n);
    }
    // int tc; cin>>tc;
    // for(int i=0; i<tc; i++){
    //     cout << "Case #" << i+1 << ": ";
    //     solve();
    // }

    return 0;
}