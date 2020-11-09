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

vvl mat;
vvl arr;

void solve(int n){
    mat.resize(0); arr.resize(0);
    mat.assign(n+1, vl(n+1, 0)); arr.assign(n, vl(n, 0));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>arr[i][j];
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            mat[i+1][j+1] = mat[i+1][j]+arr[i][j];
        }
    }

    // for(vl a : mat){
    //     for (long long b : a){
    //         cout << b << ' ';
    //     }
    //     cout << endl;
    // }
    // cout << endl;

    for(int j=0; j<n; j++){
        for(int i=0; i<n; i++){
            mat[i+1][j+1] = mat[i][j+1]+mat[i+1][j+1];
        }
    }

    // for(vl a : arr){
    //     for (long long b : a){
    //         cout << b << ' ';
    //     }
    //     cout << endl;
    // }
    // cout << endl;

    // for(vl a : mat){
    //     for (long long b : a){
    //         cout << b << ' ';
    //     }
    //     cout << endl;
    // }

    long long ans = -MAXLL;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            for(int ii=i; ii<n; ii++){
                for(int jj=j; jj<n; jj++){
                    long long area = mat[ii+1][jj+1] - mat[ii+1][j] - mat[i][jj+1] + mat[i][j];
                    ans = max(area, ans);
                    // cout << i << ',' << j << '-' << ii << ',' << jj << ": " << ans << endl;
                }
            }
        }
    }

    cout << ans << endl;
}

int main(){
    // int tc; cin>>tc;
    int n;
    while(cin>>n){
        // cout << "Case #" << i+1 << ": ";
        solve(n);
    }

    return 0;
}