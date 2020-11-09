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

string T,P;
vi b;

void kmpProcess(){
    int m = P.size();
    int i=0, j=-1;
    b.resize(0); b.assign(m+1, 0); b[0] = -1;
    while(i<m){
        while(j>=0 && P[i] != P[j]) j=b[j];
        i++; j++;
        b[i] = j;
    }
}

int kmpSearch(){
    int n=T.size(); int m = P.size();
    int i=0,j=0;
    int maxj = -MAXI;
    while(i<n){
        while(j>=0 && T[i] != P[j]) j=b[j];
        i++; j++;
        maxj = max(maxj, j);
    }

    return maxj;
}

void solve(){
    cin>>P;
    T = "";
    int n = P.size();
    for(int i=0; i<n; i++){
        T += P[n-1-i];
    }

    // cout << T << endl;
    kmpProcess();
    int j = kmpSearch();
    string ans = "";
    for(int i=j-1; i>=0; i--){
        ans+=P[i];
    }
    cout << ans << endl;
    // for(int i=0; i<b.size(); i++){
    //     cout << b[i] << endl;
    // }
}

int main(){
    int tc; cin>>tc;
    for(int i=0; i<tc; i++){
        // cout << "Case #" << i+1 << ": ";
        solve();
    }

    return 0;
}