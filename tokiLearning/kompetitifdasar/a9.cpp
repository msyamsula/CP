#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<long long> vl;
typedef vector<vl> vvl;
typedef vector<string> vs;
typedef vector<vs> vvs;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;
typedef long long ll;
#define MAXLL (1ll<<60)
#define MAXI (1<<30)

vvi mat;
int dx[4] = {0,1,0,-1}, dy[4] = {-1,0,1,0};

void walk(int i,int j){
    for(int ii=0; ii<4; ii++){
        int ni = i+dy[ii], nj = j+dx[ii];
        if (ni < 0 || ni >= mat.size() || nj<0 || nj >= mat[0].size()) continue;
        if (mat[ni][nj] == -1) continue;
        if (mat[ni][nj]-mat[i][j] <= 1) continue;
        mat[ni][nj] = min(mat[ni][nj], mat[i][j]+1);
        walk(ni,nj);
    }
}

int main(){
    mat.resize(0);
    int n,m;cin>>n>>m;
    mat.assign(n, vi(m,MAXI));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            int ntemp; cin>>ntemp;
            if (ntemp == 0) continue;
            mat[i][j] = ntemp;
        }
    }

    int y,x; cin>>y>>x;
    y--;x--;
    mat[y][x] = 1;
    
    walk(y,x);

    // for(vi artemp: mat){
    //     for(int ntemp : artemp){
    //         cout << ntemp << ' ';
    //     }
    //     cout << endl;
    // }

    int minim = MAXI;
    for(int i=0; i<n; i++){
        if (mat[i][0] == -1) continue;
        minim = min(minim, mat[i][0]);
    }

    for(int i=0; i<m; i++){
        if (mat[0][i] == -1) continue;
        minim = min(minim, mat[0][i]);
    }

    for(int i=0; i<m; i++){
        if (mat[n-1][i] == -1) continue;
        minim = min(minim, mat[n-1][i]);
    }

    for(int i=0; i<n; i++){
        if (mat[i][m-1] == -1) continue;
        minim = min(minim, mat[i][m-1]);
    }

    cout << minim << endl;

    return 0;
}
