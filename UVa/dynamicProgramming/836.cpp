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

vs grid;
vvi matsum;

void solve(){
    string line; cin>>line;
    int n = line.size();
    grid.resize(0); grid.assign(n, string(n, ' '));
    matsum.resize(0); matsum.assign(n+1, vi(n+1, 0));
    grid[0] = line;
    for(int i=1; i<n; i++){
        cin>>grid[i];
    }

    // for(string a : grid){
    //     cout << a << endl;
    // }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            matsum[i+1][j+1] = matsum[i+1][j]+int(grid[i][j]) - '0';
        }
    }

    for(int j=0; j<n; j++){
        for(int i=0; i<n; i++){
            matsum[i+1][j+1] += matsum[i][j+1];
        }
    }

    // for(vi a:matsum){
    //     for(int b:a){
    //         cout << setw(2) << setfill('0') <<b << ' ';
    //     }
    //     cout << endl;
    // }

    int marea = -MAXI;
    // int mtotal = -MAXI;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            for(int ii=i; ii<n; ii++){
                for(int jj=j; jj<n; jj++){
                    int area = matsum[ii+1][jj+1] - matsum[ii+1][j] - matsum[i][jj+1] + matsum[i][j];
                    int pop = (ii+1-i)*(jj+1-j);
                    // cout << pop << endl;
                    if (area > marea && area == pop){
                        marea = area;
                    }
                }
            }
        }
    }
    
    cout << max(0,marea) << endl;
}

int main(){
    int tc; cin>>tc;
    // cout << tc << endl;
    for(int i=0; i<tc; i++){
        // cout << "Case #" << i+1 << ": ";
        if (i!=0) cout << endl;
        string blank; getline(cin,blank);
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        // cout << (blank == "") << endl;
        solve();
    }

    return 0;
}