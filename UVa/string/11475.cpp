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

string P, T;
vi b;

void kmpProcess(){
    int m=P.size();
    int i=0,j=-1;
    b.resize(0); b.assign(m+1, 0); b[0]=-1;
    while(i<m){
        while(j>=0 && P[i] != P[j]) j=b[j];
        i++; j++;
        b[i]=j;
    }
}

int kmpSearch(){
    int n = T.size();
    int i=0,j=0;
    while(i<n){
        while(j>=0 && T[i] != P[j]) j=b[j];
        i++; j++;
    }

    return j;
}

void solve(){
    P = "";
    int n = T.size();
    for(int i=0; i<n; i++){
        P += T[n-1-i];
    }

    kmpProcess();
    int j = kmpSearch();
    P.erase(P.begin(),P.begin()+j);
    cout << T+P << endl;
}

int main(){
    // int tc; cin>>tc;
    while(cin>>T){
        // cout << "Case #" << i+1 << ": ";
        solve();
    }

    return 0;
}