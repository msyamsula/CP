#include<bits/stdc++.h>
using namespace std;

#define gs 500

typedef map<char, int> mci;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef map<ii, int> miii;

void move(char command, int &ir, int &ic, miii &visited){
    int dx[] = {0,1,0,-1}, dy[] = {-1,0,1,0};
    int icom;
    if (command == 'N'){
        icom = 0;
    } else if (command == 'E'){
        icom = 1;
    } else if (command == 'S'){
        icom = 2;
    } else if (command == 'W'){
        icom = 3;
    }

    int nic = ic + dx[icom];
    int nir = ir + dy[icom];
    while(visited.find(make_pair(nir,nic)) != visited.end()){
        // cout << ir << ' ' << ic << endl;
        ic = nic; ir = nir;
        nic = ic + dx[icom];
        nir = ir + dy[icom];
    }

    ic = nic; ir = nir;
    // cout << ir << ' ' << ic << endl;
    visited[make_pair(ir,ic)] = 1;
    // grid[ir][ic] = 1;
}

void solve(int tc){
    // cout << tc << endl;
    int n, r, c, sr, sc;
    cin>>n>>r>>c>>sr>>sc;
    string line; cin>>line;
    int ir=sr-1, ic=sc-1;
    miii visited;
    visited[make_pair(ir,ic)] = 1;
    // vi zeros(c,0);
    // vvi grid(r,zeros);
    // int grid[gs][gs] = {0};
    // for(int i=0; i<r; i++){
    //     for (int j=0; j<c; j++){
    //         cout << grid[i][j] << ' ';
    //     }
    //     cout << endl;
    // }
    // grid[ir][ic] = 1;
    for(int i=0; i<n; i++){
        // cout << i << endl;
        move(line[i],ir,ic,visited);
    }

    // for(int i=0; i<grid.size(); i++){
    //     for (int j=0; j<grid[0].size(); j++){
    //         cout << grid[i][j] << ' ';
    //     }
    //     cout << endl;
    // }

    cout << "Case #" << tc << ": " << ir+1 << ' ' << ic+1 << endl;
}

int main(){
    int tc; cin>>tc;
    for(int i=0; i<tc; i++){
        solve(i+1);
    }

    return 0;
}