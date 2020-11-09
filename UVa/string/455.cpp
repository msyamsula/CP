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

vs prefix;
vi b;
vi idxMatch;

void kmpProcess(string P){
    int m = P.size();
    int i=0, j=-1;
    b.resize(0); b.assign(m+1, 0);
    b[0] = -1;
    while(i<m){
        while(j>=0 && P[i] != P[j]) j = b[j];
        i++; j++;
        b[i] = j;
    }

}

void kmpSearch(string T, string P){
    int n = T.size(), m = P.size(), i =0, j =0;
    idxMatch.resize(0);
    while(i<n){
        while(j>=0 && T[i] != P[j]) j=b[j];
        i++; j++;
        if (j==m) idxMatch.push_back(i-j);
    }
    // for(int num : idxMatch){
    //     cout << num << ' ';
    // }
    // cout << endl;
}

bool checkInterval(int k, string T){
    for(int i=0; i<idxMatch.size(); i++){
        int next = (i == idxMatch.size()-1) ? T.size() : idxMatch[i+1];
        // cout << next << ' ';
        if (idxMatch[i]+k != next) return 0;
    }

    return 1;
}

void solve(){
    string T; cin>>T;
    int n = T.size();
    prefix.resize(0); prefix.resize(n);
    for(int i=0; i<n; i++){
        prefix[i] = T.substr(0,i+1);
    }

    for(string P : prefix){
        // cout << P << endl;
        int m = P.size();
        if (n%m == 0){
            kmpProcess(P);
            kmpSearch(T,P);
            // cout << checkInterval(m, T) << endl;
            if (checkInterval(m, T)){
                cout << m << endl;
                return;
            }
        }
    }
}

int main(){
    int tc; cin>>tc;
    for(int i=0; i<tc; i++){
        if (i!=0) cout << endl;
        // cout << "Case #" << i+1 << ": ";
        solve();
    }

    return 0;
}