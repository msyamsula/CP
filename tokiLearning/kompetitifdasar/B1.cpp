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
#define MAXLL (1ll<<60)
#define MAXI (1<<30)

int r,c;
vs mat;
string full;
string blank;

void solve(){
    cin>>r>>c;
    mat.resize(0);
    full.resize(0); full.assign(c,'1');
    blank.resize(0); blank.assign(c,'0');
    for(int i=0; i<r; i++){
        string temp; cin>>temp;
        mat.push_back(temp);
    }

    // vs temp;
    int coli;
    for(int i=0; i<r; i++){
        if (mat[i] == full){
            mat[i] = blank;
            coli = i;
        }
    }

    // for(int j=0; j<c; j++){
    //     for(int i=coli; i>=0; i--){
    //         if (mat[i][j]=='1'){
    //             mat[coli][j]= '1';
    //             mat[i][j]='0';
    //         }
    //     }
    // }

    for(string row : mat){
        cout << row << endl;
    }
    cout << coli << endl;
}

int main(){
    solve();
    // int tc; cin>>tc;
    // for(int i=0; i<tc; i++){
    //     cout << "Case #" << i+1 << ": ";
    //     solve();
    // }

    return 0;
}