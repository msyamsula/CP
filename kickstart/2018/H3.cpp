#include<bits/stdc++.h>
using namespace std;
#define MAXI pow(2,30)
#define MAXL pow(2,60)
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<long> vl;
typedef vector<vl> vvl;
typedef vector<string> vs;
typedef vector<vs> vvs;

vl factorial;
vl powertwo;
vvl pt;
long modulo = pow(10,9)+7;

void init(){
    long n = 2*100000 + 5;
    factorial.assign(n,0);
    factorial[0] = factorial[1] = 1;
    for(long i=2; i<=n; i++){
        factorial[i] = factorial[i-1]*i; factorial[i] %= modulo;
    }

    powertwo.assign(n,0);
    powertwo[0]=1;
    for(int i=1; i<n; i++){
        powertwo[i] = powertwo[i-1]*long(2); powertwo[i] %= modulo;
    }

    n = 105;
    pt.assign(n, vl(n, 0));
    pt[0][0] = 1;
    for(int i=1; i<n; i++){
        pt[i][0]=1;
        for(int j=1; j<=i; j++){
            pt[i][j] = pt[i-1][j-1] + pt[i-1][j]; pt[i][j] %= modulo;
        }
    }
}

void solve(){
    int n, m; cin>>n>>m;
    long total = factorial[2*n];    
    long bad = 0;
    for(int i=0; i<m; i++){
        int k = i+1;
        long sign = pow(-1,i);
        long part = 1;
        long a = factorial[2*n-k], b = powertwo[k], c = pt[m][k];
        part *= a; part%=modulo;
        part *= b; part%=modulo;
        part *= c; part%=modulo;
        bad += sign*part;
        if (bad < 0) bad+=modulo;
        else bad%=modulo;
    }

    total -= bad;
    if (total < 0) total += modulo;
    else total %= modulo;

    cout << total << endl;
}

int main(){
    init();
    // for(int i=0; i<=100; i++){
    //     cout << factorial[i] << ' ';
    // }
    // cout << endl;
    // for(int i=0; i<=100; i++){
    //     cout << powertwo[i] << ' ';
    // }
    // cout << endl;

    // for(vl temp : pt){
    //     for(long num : temp){
    //         cout << num << ' ';
    //     }
    //     cout << endl;
    // }
    // cout << endl;
    int tc; cin>>tc;
    for(int i=0; i<tc; i++){
        cout << "Case #" << i+1 << ": ";
        solve();
    }

    return 0;
}