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
    mat.resize(0);
    mat.assign(9, vi(9,0));
    for(int i=0; i<9; i+=2){
        for(int j=0; j<=i; j+=2){
            cin>>mat[i][j];
        }
    }

    // for(vi temp : mat){
    //     for(int num : temp){
    //         cout << num << ' ';
    //     }
    //     cout << endl;
    // }

    for(int i=1; i<9; i+=2){
        mat[8][i] = mat[6][i-1]-mat[8][i-1]-mat[8][i+1];
        mat[8][i] /= 2;
    }

    for(int i=7; i>=0; i--){
        for(int j=0; j<=i; j++){
            mat[i][j] = mat[i+1][j] + mat[i+1][j+1];
        }
    }

    for(int i=0; i<9; i++){
        for(int j=0; j<=i; j++){
            cout << mat[i][j] << " \n"[j==i];
        }
    }
    // for(vi temp : mat){
    //     for(int num : temp){
    //         cout << num << ' ';
    //     }
    //     cout << endl;
    // }
}

int main(){
    int tc; cin>>tc;
    for(int i=0; i<tc; i++){
        // cout << "Case #" << i+1 << ": ";
        solve();
    }

    return 0;
}