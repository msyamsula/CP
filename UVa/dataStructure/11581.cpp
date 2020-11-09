#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<long> vl;
typedef vector<vl> vvl;
typedef vector<string> vs;
typedef vector<vs> vvs;

vvi mat;
vvi trf;
int n=3;
int dx[4] = {0,1,0,-1}, dy[4] = {-1,0,1,0};
vvi zonk;

void transform(){
    vvi temp = trf;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            int sum = 0;
            for(int ii=0; ii<4; ii++){
                // cout << "tes" << endl;
                int ni = i+dy[ii], nj = j+dx[ii];
                if (ni<0 || ni>=n || nj<0 || nj>=n) continue;
                sum += trf[ni][nj]; sum%=2;
            }
            temp[i][j] = sum;
        }
    }
    trf = temp;
}

void solve(){
    mat.resize(0);
    mat.assign(n, vi(n,-1));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            char a; cin>>a;
            mat[i][j] = int(a)-'0';
        }
    }
    trf = mat;

    // for(vi temp: mat){
    //     for(int num : temp){
    //         cout << num;
    //     }
    //     cout << endl;
    // }
    // cout << endl;


    // for(int i=0; i<10; i++){
    //     transform();
    //     for(int ii=0; ii<n; ii++){
    //         for(int jj=0; jj<n; jj++){
    //             cout << trf[ii][jj];
    //         }
    //         cout << endl;
    //     }
    //     cout << endl;
    // }

    int ans = -1;
    while(trf != zonk){
        transform();
        ans++;
    }

    cout << ans << endl;

}

int main(){
    zonk.assign(n, vi(n,0));
    int tc; cin>>tc;
    for(int i=0; i<tc; i++){
        // cout << "Case #" << i+1 << ": ";
        solve();
    }

    return 0;
}