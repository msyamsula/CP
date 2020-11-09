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

vvl matsum;
vvl mat;
vvl result;

void solve(int n, int m){
    mat.resize(0); matsum.resize(0); result.resize(0);
    mat.assign(n, vl(n, 0)); matsum.assign(n+1, vl(n+1, 0));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            int ii = n-1-i, jj = j;
            cin>>mat[ii][jj];
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            matsum[i+1][j+1] = matsum[i+1][j] + matsum[i][j+1] + mat[i][j] - matsum[i][j];
        }
    }

    for(int i=0; i<=n-m; i++){
        vl temp;
        for(int j=0; j<=n-m; j++){
            int is=i, js=j, ie=is+m, je=js+m;
            long long sum = matsum[ie][je] - matsum[is][je] - matsum[ie][js] + matsum[is][js];
            temp.push_back(sum);
        }
        result.push_back(temp);
    }

    long long sum = 0;
    for(int i=0; i<result.size(); i++){
        for(int j=0; j<result.size(); j++){ 
            int ii = result.size()-1-i, jj = j;
            // cout << ii << ' ' << jj << endl;
            cout << result[ii][jj] << endl;
            sum += result[ii][jj];
        }
    }
    cout << sum << endl;
    // cout << "tes" << endl;
}

int main(){
    // int tc; cin>>tc;
    int n, m;
    int i=0;
    while(cin>>n>>m){
        // cout << "Case #" << i+1 << ": ";
        if(i!=0) cout << endl;
        solve(n,m);
        i++;
    }

    return 0;
}