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

vvl grid, sum2d;

void solve(){
    int n,m; cin>>n>>m;
    long long k; cin>>k;
    grid.resize(0); grid.assign(n, vl(m, 0));
    sum2d.resize(0); sum2d.assign(n+1, vl(m+1, 0));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>grid[i][j];
            sum2d[i+1][j+1] = grid[i][j] + sum2d[i+1][j] + sum2d[i][j+1] - sum2d[i][j];
        }
    }

    // for(vl a : grid){
    //     for (long long b : a){
    //         cout << b << ' ';
    //     }
    //     cout << endl;
    // }
    // cout << endl;

    // for(vl a : sum2d){
    //     for (long long b : a){
    //         cout << b << ' ';
    //     }
    //     cout << endl;
    // }
    // cout << endl;

    long long harea = -MAXLL;
    long long hprice = MAXLL;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            for(int ii=i; ii<n; ii++){
                for(int jj=j; jj<m; jj++){
                    long long price = sum2d[ii+1][jj+1] - sum2d[ii+1][j] - sum2d[i][jj+1] + sum2d[i][j];
                    long long area = (ii+1-i)*(jj+1-j);
                    // bool s1 = (price < hprice) && (area >= harea);
                    // bool s2 = ()
                    bool buy = (price <= k);
                    bool better = (area >= harea && price<hprice) || (price>=hprice && area>harea);
                    if (buy && better){
                        harea = area;
                        hprice = price;
                        // string start = to_string(i)+','+to_string(j);
                        // string end = to_string(ii)+','+to_string(jj);
                        // cout << start << ' ' << end << ' ' << harea << ' ' << hprice << endl;
                    }
                }
            }
        }
    }

    cout << max(0ll,harea) << ' ' << ((hprice == MAXLL) ? 0 : hprice) << endl;

}

int main(){
    int tc; cin>>tc;
    for(int i=0; i<tc; i++){
        cout << "Case #" << i+1 << ": ";
        solve();
    }

    return 0;
}