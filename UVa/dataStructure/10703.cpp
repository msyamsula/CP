#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<long> vl;
typedef vector<vl> vvl;
typedef vector<string> vs;
typedef vector<vs> vvs;

vvi mat;

void sub(int x1, int y1, int x2, int y2){
    int ystart = min(y1,y2), yend=max(y1,y2);
    int xstart = min(x1,x2), xend=max(x1,x2);
    for(int i=ystart; i<=yend; i++){
        for(int j=xstart; j<=xend; j++){
            mat[i][j] = 0;
        }
    }
}

void solve(int w,int h, int n){
    mat.resize(0);
    mat.assign(h, vi(w, 1));
    for(int i=0; i<n; i++){
        int x1, y1, x2, y2;
        cin>>x1>>y1>>x2>>y2;
        x1--;y1--;x2--;y2--;
        sub(x1,y1,x2,y2);
    }

    int total = 0;
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            total += mat[i][j];
        }
    }

    // for(vi temp: mat){
    //     for(int a: temp){
    //         cout << a << ' ';
    //     }
    //     cout << endl;
    // }

    if (total ==0 ){
        cout << "There is no empty spots." << endl;
        return;
    } else if (total == 1){
        cout << "There is one empty spot." << endl;
        return;
    }

    cout << "There are " <<total<< " empty spots." << endl;
}

int main(){
    int w,h,n;
    while(cin>>w>>h>>n){
        if (!w && !h && !n) break;
        // cout << "Case #" << i+1 << ": ";
        solve(w,h,n);
    }

    return 0;
}