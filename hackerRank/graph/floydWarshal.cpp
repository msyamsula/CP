#include<bits/stdc++.h>
using namespace std;
#define MAX_N 1l<<40
typedef vector<long> vi;
typedef vector<vi> vvi;

int main(){
    int n,m; cin>>n>>m;
    // vvi adjMat(n, vi(n,MAX_N));
    vvi graph(n+1);
    for(int i=0; i<n; i++){
        
        // adjMat[i][i] = 0;
    }

    for(int i=0; i<m; i++){
        int u,v,d; cin>>u>>v>>d;
        adjMat[u][v] = d;
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << adjMat[i][j] << ' ';
        }
        cout << endl;
    }
    cout << endl;

    for(int k=0; k<n; k++){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                adjMat[i][j] = min(adjMat[i][j],adjMat[i][k] + adjMat[k][j]);
                cout << adjMat[i][j] << ' ';
            }
            cout << endl;
        }
        cout << endl;

        // for(int i=0; i<n; i++){
        //     for(int j=0; j<n; j++){
        //         cout << adjMat[i][j] << ' ';
        //     }
        //     cout << endl;
        // }
    }

    return 0;
}