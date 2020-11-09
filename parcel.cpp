#include<bits/stdc++.h>
using namespace std;

typedef vector<string> vs;
typedef vector<int> vi;

void solve(int tc){
    int n; cin>>n;
    int m; cin>>m;
    vs line(n);
    for (int i=0; i<n; i++){
        cin>>line[i];
    }

    vi mind(n*m);


    for(int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            int idx = i*m+j;
            if (line[i][j] == '1'){
                mind[idx] = 0;
                continue;   
            }

            int min = 1<<30;
            for (int ii=0; ii<n; ii++){
                for (int jj=0; jj<m; jj++){
                    if (line[ii][jj] == '0') continue;
                    int dx = (ii>i) ? ii-i : i-ii;
                    int dy = (jj>j) ? jj-j : j-jj;
                    int mandis = dx+dy;
                    if (mandis < min) min = mandis;
                }
            }
            mind[idx] = min;
        }
    }

    // for (int i=0; i<n; i++){
    //     for (int j=0; j<m; j++){
    //         cout << line[i][j] << ' ';
    //     }
    //     cout << endl;
    // }

    // for (int i=0; i<n*m; i++){
    //     cout << mind[i] << ' ';
    // }
    // cout << endl;

    int mint = *max_element(mind.begin(), mind.end());
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            if (line[i][j] == '1') continue;
            vi artemp = mind;
            int idx = i*m+j;
            artemp[idx] = 0;
            for (int ii=0; ii<n; ii++){
                for (int jj=0; jj<m; jj++){
                    int idx2 = ii*m+jj;
                    int mandis = abs(jj-j) + abs(ii-i);
                    artemp[idx2] = min(artemp[idx2], mandis);
                }
            }

            int newmint = *max_element(artemp.begin(), artemp.end());
            if (newmint < mint) mint = newmint;
        }
    }

    cout << "Case #" << tc << ": " << mint << endl;

}


int main(){
    int tc; cin>>tc;
    for (int i=0; i<tc; i++){
        solve(i+1);
    }

    return 0;
}