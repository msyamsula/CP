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
#define MAXLL (1ll<<60)
#define MAXI (1<<30)

string T;
vs pat;
string P;
vi b;
vi mi;

void kmpProcess(){
    int m = P.size();
    int i=0, j=-1;
    b.resize(0); b.assign(m+1, 0); b[0] = -1;
    while(i<m){
        while (j>=0 && P[i] != P[j]){
            // cout << i << ' ' << j << endl;
            j=b[j];
            // cout << i << ' ' << j << endl;
            // cout << P[i] << ' ' << P[j] << endl;
            // cout << (j>=0 && P[i] != P[j]) << endl;
        }
        // cout << j << endl;
        i++; j++;
        // cout << j << endl;
        b[i] = j;
    }
}

void solve(){
    P = T;
    // cout << P << endl;
    kmpProcess();
    int m = P.size();
    int ii = -1;
    int p = 0;
    for(int i=1; i<=m; i++){
        if (b[i] == 1){
            ii = i; break;
        } else if (b[i]==0){
            p++;
        }
    }

    for(int i=0; i<m+1; i++){
        cout << b[i] << ' ' << i << endl;
    }

    int ps = b[m];
    // cout << ps << endl;
    if (2*ps >= m) cout << m/(m-ps) << endl;
    else cout << 1 << endl;

    // int periodic = 1;
    // for(int i=ii; i<m; i++){
    //     if (b[i]+1 != b[i+1]){
    //         periodic = 0; break;
    //     }
    // }

    // if (periodic){
    //     int last = b[b.size()-1];
    //     if (last%p == 0){
    //         cout << last/p << endl;
    //     }
    // }

    // cout << 1 << endl;
}

int main(){
    // int tc; cin>>tc;
    // string T
    while(cin>>T){
        // cout << "Case #" << i+1 << ": ";
        if (T==".") break;
        solve();
    }

    return 0;
}