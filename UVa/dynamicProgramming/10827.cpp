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

vvl mat, matsum, mmatsum, mmat;

void transpose(){
    vvl temp=mat;
    vvl mtemp=mmat;
    int n=mat.size();
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            temp[i][j] = mat[j][i];
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            mtemp[i][j] = temp[i][n-1-j];
        }
    }

    mat = temp; mmat = mtemp;
}

long long torus(){
    int n = mat.size();
    matsum.resize(0); matsum.assign(n+1, vl(n+1, 0));
    mmatsum.resize(0); mmatsum.assign(n+1, vl(n+1, 0));

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            matsum[i+1][j+1] = mat[i][j]+matsum[i][j+1]+matsum[i+1][j]-matsum[i][j];
            mmatsum[i+1][j+1] = mmat[i][j]+mmatsum[i][j+1]+mmatsum[i+1][j]-mmatsum[i][j];
        }
    }

    long long big = -MAXLL;
    for(int i=0; i<n; i++){
        for(int ii=i; ii<n; ii++){
            for(int jj=0; jj<n; jj++){
                long long sum = matsum[ii+1][jj+1]-matsum[i][jj+1]-matsum[ii+1][0]+matsum[i][0];
                long long csum = sum;
                for(int jc=0; jc<n-jj-1; jc++){
                    // cout << jj+jc << endl;
                    long long msum = mmatsum[ii+1][jc+1]-mmatsum[i][jc+1]-mmatsum[ii+1][0]+mmatsum[i][0];
                    csum = max(csum, msum+sum);
                }
                big = max(big, csum);
                // cout << big << endl;
            }
        }
    }

    return big;

}

void solve(){
    int n; cin>>n;
    mat.resize(0); mat.assign(n, vl(n, 0));
    mmat.resize(0); mmat.assign(n, vl(n, 0));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>mat[i][j];
            mmat[i][n-1-j] = mat[i][j];
        }
    }
    
    long long htorus = torus();
    // for(vl a : mat){
    //     for( long long b : a){
    //         cout << b << ' ';
    //     }
    //     cout << endl;
    // }
    // cout << endl;

    // for(vl a : mmat){
    //     for( long long b : a){
    //         cout << b << ' ';
    //     }
    //     cout << endl;
    // }
    // cout << endl;
    transpose();
    long long vtorus = torus();

    // cout << vtorus << ' ' << htorus << endl;
    cout << max(htorus, vtorus) << endl;


    // for(vl a : mat){
    //     for( long long b : a){
    //         cout << b << ' ';
    //     }
    //     cout << endl;
    // }
    // cout << endl;

    // // mirror();
    // for(vl a : mmat){
    //     for( long long b : a){
    //         cout << b << ' ';
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