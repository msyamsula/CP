#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<long> vl;
typedef vector<vl> vvl;
typedef vector<string> vs;
typedef vector<vs> vvs;

vvi mat;

void updown(int ring){
    int n = mat.size();
    vvi temp=mat;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            temp[i][j] = mat[n-1-i][j];
        }
    }

    int start = ring, end = n-ring;
    for(int i=start; i<end; i++){
        mat[ring][i] = temp[ring][i];
    }

    for(int i=start; i<end; i++){
        mat[i][ring] = temp[i][ring];
    }

    for(int i=start; i<end; i++){
        mat[n-1-ring][i] = temp[n-1-ring][i];
    }

    for(int i=start; i<end; i++){
        mat[i][n-1-ring] = temp[i][n-1-ring];
    }
}

void leftRight(int ring){
    int n = mat.size();
    vvi temp=mat;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            temp[i][j] = mat[i][n-1-j];
        }
    }

    int start = ring, end = n-ring;
    for(int i=start; i<end; i++){
        mat[ring][i] = temp[ring][i];
    }

    for(int i=start; i<end; i++){
        mat[i][ring] = temp[i][ring];
    }

    for(int i=start; i<end; i++){
        mat[n-1-ring][i] = temp[n-1-ring][i];
    }

    for(int i=start; i<end; i++){
        mat[i][n-1-ring] = temp[i][n-1-ring];
    }
}

void mainDiag(int ring){
    int n = mat.size();
    vvi temp=mat;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            temp[i][j] = mat[j][i];
        }
    }

    int start = ring, end = n-ring;
    for(int i=start; i<end; i++){
        mat[ring][i] = temp[ring][i];
    }

    for(int i=start; i<end; i++){
        mat[i][ring] = temp[i][ring];
    }

    for(int i=start; i<end; i++){
        mat[n-1-ring][i] = temp[n-1-ring][i];
    }

    for(int i=start; i<end; i++){
        mat[i][n-1-ring] = temp[i][n-1-ring];
    }
}

void InvMainDiag(int ring){
    int n = mat.size();
    vvi temp=mat;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            temp[i][j] = mat[n-1-j][n-1-i];
            // cout << temp[i][j] << ' ';
        }
        // cout << endl;
    }

    int start = ring, end = n-ring;
    for(int i=start; i<end; i++){
        mat[ring][i] = temp[ring][i];
    }

    for(int i=start; i<end; i++){
        mat[i][ring] = temp[i][ring];
    }

    for(int i=start; i<end; i++){
        mat[n-1-ring][i] = temp[n-1-ring][i];
    }

    for(int i=start; i<end; i++){
        mat[i][n-1-ring] = temp[i][n-1-ring];
    }
}

void solve(){
    int n; cin>>n;
    mat.resize(0);
    mat.assign(n, vi(n,0));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>mat[i][j];
        }
    }

    // cout << "init" << endl;
    // for(vi temp: mat){
    //     for(int num : temp){
    //         cout << num << ' ';
    //     }
    //     cout << endl;
    // }
    // cout << endl;

    // cout << "transform" << endl;
    // InvMainDiag(1);
    // for(vi temp: mat){
    //     for(int num : temp){
    //         cout << num << ' ';
    //     }
    //     cout << endl;
    // }

    int ring = (n+1)/2;
    // cout << "ring " << ring << endl;
    for(int i=0; i<ring; i++){
        int t; cin>>t;
        for(int j=0; j<t; j++){
            int a; cin>>a;
            // cout << a << endl;
            if (a==1){
                updown(i);
            } else if (a==2){
                leftRight(i);
            } else if (a==3){
                mainDiag(i);
            } else if (a==4){
                InvMainDiag(i);
            }
            // for(int i=0; i<n; i++){
            //     for(int j=0; j<n; j++){
            //         cout << mat[i][j] << " \n"[j==n-1];
            //     }
            // }
            // cout << endl;
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << mat[i][j] << " \n"[j==n-1];
        }
    }

}

int main(){
    int tc; cin>>tc;
    for(int i=0; i<tc; i++){
        // cout << "Case #" << i+1 << ": ";
        solve();
    }

    return 0;
}