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

int main(){
    mat.resize(0);
    int n, m, k; cin>>n>>m>>k;
    for(int i=0; i<n; i++){
        vi arr;
        for(int j=0; j<m; j++){
            int temp; cin>>temp;
            arr.push_back(temp);
        }
        mat.push_back(arr);
    }

    vi dx = {0,1,0,-1}, dy = {1,0,-1,0};
    for(int j=0; j<m; j++){
        for(int i=0; i<n; i++){
            int ktemp = 1;
            for(int ii=0; ii<4; ii++){
                int ni = i+dy[ii], nj = j+dx[ii];
                if (ni<0 || ni>=n || nj<0 || nj>=m) continue;
                ktemp *= mat[ni][nj];
            }
            if (ktemp==k){
                cout << i+1 << ' ' << j+1 << endl;
                return 0;
            }
        }
    }

    cout << 0 << ' ' << 0 << endl;


    return 0;
}
