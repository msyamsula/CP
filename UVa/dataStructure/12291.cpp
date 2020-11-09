#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<long> vl;
typedef vector<vl> vvl;
typedef vector<string> vs;
typedef vector<vs> vvs;

vs big, small, zonk;


void evaluate(int i, int j, int nsmall){
    int m = big.size(), n1 = small.size(), n2 = small[0].size();
    vs temp(n1,string(n2, '.'));
    for(int ii=i; ii<i+n1; ii++){
        for(int jj=j; jj<j+n2; jj++){
            temp[ii-i][jj-j] = big[ii][jj];
        }
    }

    

    int ntemp = 0;
    for(int ii=0; ii<n1; ii++){
        for(int jj=0; jj<n2; jj++){
            if (temp[ii][jj] == '*' && small[ii][jj]=='*') ntemp++;
        }
    }
    // cout << ntemp << ' ' << nsmall << endl;

    if (nsmall == ntemp){
        for(int ii=i; ii<i+n1; ii++){
            for(int jj=j; jj<j+n2; jj++){
                if (small[ii-i][jj-j] == '*') big[ii][jj] = '.';
            }
        }
    }   

    // for(string t : big){
    //     cout << t << endl;
    // }

}

void solve(int m, int n){
    big.resize(0); big.assign(m, string(m, '.'));
    small.resize(0); small.assign(n, string(n, '.'));
    int nbig = 0;
    for(int i=0; i<m; i++){
        for (int j=0; j<m; j++){
            char a; cin>>a;
            if (a == '*') nbig++;
            big[i][j] = a;
        }
    }

    // for(string a : big){
    //     cout << a << endl;
    // }

    int nsmall = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            char a; cin>>a;
            if (a=='*') nsmall++;
            small[i][j] = a;
        }
    }
    if (nsmall == 0){
        cout << 0 << endl; return;
    }

    int istart=-1, iend=n, jstart=-1, jend=n;

    for(int i=0; i<n; i++){
        bool found = 0;
        for(int j=0; j<n; j++){
            if (small[i][j] == '*') found = 1;
        }
        if (found){
            istart = i;
            break;
        }
    }

    for(int i=n-1; i>=0; i--){
        bool found = 0;
        for(int j=0; j<n; j++){
            if (small[i][j] == '*') found = 1;
        }
        if (found){
            iend = i;
            break;
        }
    }

    for(int j=0; j<n; j++){
        bool found = 0;
        for(int i=0; i<n; i++){
            if (small[i][j] == '*') found = 1;
        }
        if (found){
            jstart = j;
            break;
        }
    }

    for(int j=n-1; j>=0; j--){
        bool found = 0;
        for(int i=0; i<n; i++){
            if (small[i][j] == '*') found = 1;
        }
        if (found){
            jend = j;
            break;
        }
    }

    vs temp((iend-istart+1), string(jend-jstart+1, '.'));
    for(int i=istart; i<=iend; i++){
        for(int j=jstart; j<=jend; j++){
            temp[i-istart][j-jstart] = small[i][j];
        }
    }

    // small.resize(iend-istart);
    // cout << istart << ' ' << iend << endl;
    // cout << jstart << ' ' << jend << endl;
    small = temp;

    // for(string a : small){
    //     cout << a << endl;
    // }
    // for(string a : small){
    //     cout << a << endl;
    // }

    // cout << nbig << ' ' << nsmall << endl;

    // if (nbig % nsmall != 0){
    //     cout << 0 << endl; return;
    // }

    // cout << "tes" << endl;
    int n1 = small.size(), n2 = small[0].size();
    for(int i=0; i<=m-n1; i++){
        for(int j=0; j<=m-n2; j++){
            // cout << i << ' ' << j << endl;
            evaluate(i,j,nsmall);
        }
    }

    if (big == zonk) cout << 1 << endl;
    else cout << 0 << endl;

}

int main(){
    int m,n;
    while(cin>>m>>n){
        if (!m && !n) break;
        zonk.resize(0); zonk.assign(m, string(m, '.'));
        // cout << "Case #" << i+1 << ": ";
        solve(m,n);
    }

    return 0;
}