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

void solve(){
    int n; cin>>n;
    mat.resize(0); mat.assign(n, vi(n, 0));
    matsum.resize(0); matsum.assign(n+1, vi(n+1, 0));
    int b; cin>>b;
    for(int i=0; i<b; i++){
        int is,js,ie,je; cin>>is>>js>>ie>>je;
        is--;js--;ie--;je--;
        for(int r=is; r<=ie; r++){
            for(int c=js; c<=je; c++){
                mat[r][c] = 1;
            }
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            matsum[i+1][j+1] = mat[i][j] + matsum[i][j+1] + matsum[i+1][j] - matsum[i][j];
        }
    }

    int marea = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            for(int ii=i; ii<n; ii++){
                for(int jj=j; jj<n; jj++){
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
    int tc; cin>>tc;
    for(int i=0; i<tc; i++){
        // cout << "Case #" << i+1 << ": ";
        solve();
    }

    return 0;
}