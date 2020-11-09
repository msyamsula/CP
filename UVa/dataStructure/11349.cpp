#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<long> vl;
typedef vector<vl> vvl;
typedef vector<string> vs;
typedef vector<vs> vvs;

vvi mat;

void solve(){
    string N,eq; cin>>N>>eq;
    int n; cin>>n;
    mat.resize(0);
    mat.assign(n, vi(n,0));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>mat[i][j];
        }
    }

    // for(vi a : mat){
    //     for(int b : a){
    //         cout << b << ' ';
    //     }
    //     cout << endl;
    // }

    vvi temp=mat;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            temp[i][j] = mat[n-1-j][n-1-i];
        }
    }
    // cout << endl;

    // for(vi a : temp){
    //     for(int b : a){
    //         cout << b << ' ';
    //     }
    //     cout << endl;
    // }

    vvi tempT=temp;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            tempT[i][j] = temp[j][i];
        }
    }
    // cout << endl;

    // for(vi a : tempT){
    //     for(int b : a){
    //         cout << b << ' ';
    //     }
    //     cout << endl;
    // }

    if (tempT == mat) cout << "Symmetric." << endl;
    else cout << "Non-symmetric." << endl;

}

int main(){
    int tc; cin>>tc;
    for(int i=0; i<tc; i++){
        cout << "Test #" << i+1 << ": ";
        solve();
    }

    return 0;
}