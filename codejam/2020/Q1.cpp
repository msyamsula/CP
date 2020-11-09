#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;

void solve(){
    int n;cin>>n;
    vvi grid(n, vi(n,0));
    for(int i = 0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>grid[i][j];
        }
    }
    int trace = 0;
    for(int i=0; i<n; i++){
        trace += grid[i][i];
    }

    int repeatRow = 0, repeatCol = 0;
    for(int i=0; i<n; i++){
        set<int> s;
        for(int j=0; j<n; j++){
            s.insert(grid[i][j]);
        }
        if (s.size() != n) repeatRow++;
    }

    for(int j=0; j<n; j++){
        set<int> s;
        for(int i=0; i<n; i++){
            s.insert(grid[i][j]);
        }
        if (s.size() != n) repeatCol++;
    }

    cout << trace << ' ' << repeatRow << ' ' << repeatCol << endl;
    // for (int i=0; i<n; i++){
    //     for(int j=0; j<n; j++){
    //         set<int> s;
    //         s.insert(grid[i][j]);
    //         for(int ii=0; ii<n; ii++){
    //             s.insert(grid[i][ii]);
    //             s.insert(grid[ii][j]);
    //         }

    //         if (s.size() != 2*n-1)
    //     }
    // }
}

int main(){
    int tc; cin>>tc;
    for(int i=0; i<tc; i++){
        cout <<"Case #" << i+1 << ": ";
        solve();
    }

    return 0;
}