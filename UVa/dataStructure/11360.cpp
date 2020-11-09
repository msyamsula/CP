#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<long> vl;
typedef vector<vl> vvl;
typedef vector<string> vs;
typedef vector<vs> vvs;

vvi mat;

void srow(int a,int b){
    vi temp;
    temp = mat[a];
    mat[a] = mat[b];
    mat[b] = temp;
}

void transpose(){
    int n = mat.size();
    vvi temp=mat;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            temp[i][j] = mat[j][i];
        }
    }

    mat = temp;
}

void inc(){
    int n = mat.size();
    vvi temp = mat;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            temp[i][j] = mat[i][j]+1;
            temp[i][j] %= 10;
        }
    }

    mat = temp;
}

void dec(){
    int n = mat.size();
    vvi temp = mat;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            temp[i][j] = mat[i][j]-1;
            if (temp[i][j] < 0) temp[i][j] += 10;
            temp[i][j] %= 10;
        }
    }

    mat = temp;
}


void scol(int a,int b){
    transpose();
    vi temp;
    temp = mat[a];
    mat[a] = mat[b];
    mat[b] = temp;
    transpose();
}

void solve(){
    int n; cin>>n;
    mat.resize(0); mat.assign(n, vi(n,0));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            char a; cin>>a;
            // cout << a << endl;
            int num = int(a)-'0';
            mat[i][j] = num;
        }
    }

    // for(vi temp: mat){
    //     for(int a : temp){
    //         cout << a << ' ';
    //     }
    //     cout << endl;
    // }

    int m; cin>>m;
    for(int i=0; i<m; i++){
        string c; cin>>c;
        if (c == "transpose"){
            transpose();
        } else if (c == "inc"){
            inc();
        } else if (c == "dec"){
            dec();
        } else if (c == "row"){
            int a,b; cin>>a>>b;
            a--; b--;
            srow(a,b);
        } else if (c == "col"){
            int a,b; cin>>a>>b;
            a--; b--;
            scol(a,b);
        }
    }

    for(vi temp: mat){
        for(int i=0; i<n; i++){
            cout << temp[i];
        }
        cout << endl;
    }
    cout << endl;

}

int main(){
    int tc; cin>>tc;
    for(int i=0; i<tc; i++){
        cout << "Case #" << i+1 << endl;
        solve();
    }

    return 0;
}