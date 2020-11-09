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
vvi mat2;

bool identity(){
    return mat == mat2;
}

bool hor(){
    int n=mat.size(), m=mat[0].size();
    vvi mtemp(n, vi(m,0));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            mtemp[i][j] = mat[n-1-i][j];
        }   
    }

    return mtemp==mat2;
}

bool ver(){
    int n=mat.size(), m=mat[0].size();
    vvi mtemp(n, vi(m,0));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            mtemp[i][j] = mat[i][m-1-j];
        }   
    }

    return mtemp==mat2;
} 

bool maind(){
    int n=mat.size(), m=mat[0].size();
    vvi mtemp(n, vi(m,0));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            mtemp[i][j] = mat[n-1-j][n-1-i];
        }   
    }

    return mtemp==mat2;
}

bool secondd(){
    int n=mat.size(), m=mat[0].size();
    vvi mtemp(n, vi(m,0));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            mtemp[i][j] = mat[j][i];
        }   
    }

    return mtemp==mat2;
}

void solve(int n, int m){
    mat.resize(0); mat2.resize(0);
    for(int i=0; i<n; i++){
        vi vtemp;
        for(int j=0; j<m; j++){
            int ntemp; cin>>ntemp;
            vtemp.push_back(ntemp);
        }
        mat.push_back(vtemp);
    }

    cin>>n>>m;
    for(int i=0; i<n; i++){
        vi vtemp;
        for(int j=0; j<m; j++){
            int ntemp; cin>>ntemp;
            vtemp.push_back(ntemp);
        }
        mat2.push_back(vtemp);
    }

    if (identity()){
        cout << "identik" << endl;
    } else if (hor()){
        cout << "horisontal" << endl;
    } else if (ver()){
        cout << "vertikal" << endl;
    } else if (maind()){
        cout << "diagonal kiri bawah" << endl;
    } else if (secondd()){
        cout << "diagonal kanan bawah" << endl;
    } else {
        cout << "tidak identik" << endl;
    }
}

int main(){
    int n,m;
    while(cin>>n>>m){
        solve(n,m);
    }
    return 0;
}
