#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

void solve(){
    int k; cin>>k;
    int sz = k+1;
    vi front(k,0), right(k,0);
    for (int i=0; i<k; i++){
        cin >> front[i];
    }

    for (int i=0; i<k; i++){
        cin>>right[i];
    }


    int maxsum = 0;
    for (int i=0; i<k; i++){
        for (int j=0; j<k; j++){
            maxsum += min(right[i], front[j]);
            // cout << table[i][j] << " \n"[j==k-1];
            // maxsum += table[i][j];
        }
    }

    // for (int i=0; i<k; i++){
    //     table[0][i] = table[k][i];
    // }

    // for (int i=0; i<sz-2; i++){
    //     for (int j=0; j<sz-1; j++){
    //         if (table[i][j] > table[i][k]){
    //             table[i+1][j] = table[i][j];
    //             table[i][j] = -1;
    //         } else if (table[i][j] == table[i][k]){
    //             int jj=j+1;
    //             for (int iter=0; iter<k-1; iter++){
    //                 int jidx = (jj+iter)%k;
    //                 table[i+1][jidx] = table[i][jidx];
    //                 table[i][jidx] = -1;
    //             }
    //             break;
    //         }
    //     }
    // }

    int minsum = 0;
    vi used(k,0);
    for (int i=0; i<k; i++){
        bool pass = 1;
        for(int j=0; j<k; j++){
            if (used[j] == 1) continue;
            if (front[j] == right[i]){
                used[j] = 1;
                minsum+=front[j];
                pass = 0;
                break;
            }
        }
        // cout << i << ' ' << pass << endl;
        if (pass) minsum += right[i];
    }

    for (int i=0; i<k; i++){
        if (used[i] == 1) continue;
        minsum += front[i];
        // cout << used[i] << ' ' << front[i] << endl;
    }
    // for (int i=0; i<sz-1; i++){
    //     for (int j=0; j<sz-1; j++){
    //         // cout << table[i][j] << " \n"[j==sz-2];
    //         if (table[i][j] == -1) continue;
    //         else if (table[i][j] == table[i][k]){
    //             minsum += table[i][j];
    //             break;
    //         } else if (table[i][j] < table[i][k] && table[i][j] > -1){
    //             minsum += table[i][j] + table[i][k];
    //             break;
    //         }
    //     }
    // }

    // for (int i=0; i<sz; i++){
    //     for (int j=0; j<sz; j++){
    //         cout << table[i][j] << "      ";
    //     }
    //     cout << endl;
    // }

    // cout << minsum << ' ' << maxsum << endl;
    cout << "Matty needs at least "<< minsum <<" blocks, and can add at most " << maxsum-minsum << " extra blocks." << endl;
}

int main(){
    int tc; cin>>tc;
    for (int i=0; i<tc; i++){
        solve();
    }

    return 0;
}