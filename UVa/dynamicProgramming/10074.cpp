#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<long long> vl;
typedef vector<vl> vvl;
typedef vector<string> vs;
typedef vector<vs> vvs;
#define MAXLL (1ll<<60)
#define MAXI (1<<30)

vvi matsum;
vvi mat;

void solve(int R, int C){
    mat.resize(0); mat.assign(R, vi(C, 0));
    matsum.resize(0); matsum.assign(R+1, vi(C+1, 0));
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            cin>>mat[i][j];
        }
    }

    // for(vi a : mat){
    //     for(int b : a){
    //         cout << b << ' ';
    //     }
    //     cout << endl;
    // }
    // cout << endl;

    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            matsum[i+1][j+1] = mat[i][j] + matsum[i][j+1] + matsum[i+1][j] - matsum[i][j];
        }
    }

    // for(vi a : matsum){
    //     for(int b : a){
    //         cout << b << ' ';
    //     }
    //     cout << endl;
    // }
    // cout << endl;

    int marea = 0;
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            for(int ii=i; ii<R; ii++){
                for(int jj=j; jj<C; jj++){
                    int sum = matsum[ii+1][jj+1] - matsum[i][jj+1] - matsum[ii+1][j] + matsum[i][j];
                    if (sum == 0){
                        marea = max(marea, (ii+1-i)*(jj+1-j));
                    }
                }
            }
        }
    }

    cout << marea << endl;
}

int main(){
    // int tc; cin>>tc;
    int R, C;
    while(cin>>R>>C){
        if (!R && !C) break;
        // cout << "Case #" << i+1 << ": ";
        solve(R,C);
    }

    return 0;
}