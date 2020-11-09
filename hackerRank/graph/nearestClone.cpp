#include<bits/stdc++.h>
using namespace std;
#define MAX_N pow(2,50)
#define MIN_N -MAX_N
typedef vector<long> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef vector<vi> vvi; 


int main(){
    int n,m; cin>>n>>m;
    // vvi graph(n+1);
    vi color(n+1);
    vvi adjMat(n+1, vi(n+1, MAX_N));
    for(int i=0; i<=n; i++){
        adjMat[i][i] = 0;
    }

    for(int i=0; i<m; i++){
        long u,v; cin>>u>>v;
        adjMat[u][v] = 1;
        adjMat[v][u] = 1;
    }

    for(int i=1; i<=n; i++){
        cin>>color[i];
    }
    long target; cin>>target;

    // for(int i=1; i<=n; i++){
    //     for(int j=1; j<=n; j++){
    //         // if (i==j) continue;
    //         cout << adjMat[i][j] << ' ';
    //     }
    //     cout << endl;
    // }
    // cout << endl;

    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for( int j=1; j<=n; j++){
                adjMat[i][j] = min(adjMat[i][k]+adjMat[k][j], adjMat[i][j]);
            }
        }
    }

    long minimal = MAX_N;
    for (int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if (i==j) continue;
            if (color[i] == color[j] && color[i] == target){
                minimal = min(minimal, adjMat[i][j]); 
            }
        }
    }

    // for(int i=1; i<=n; i++){
    //     for(int j=1; j<=n; j++){
    //         cout << adjMat[i][j] << ' ';
    //     }
    //     cout << endl;
    // }

    minimal = (minimal == MAX_N) ? -1 : minimal;
    cout << minimal << endl;

    return 0;
}