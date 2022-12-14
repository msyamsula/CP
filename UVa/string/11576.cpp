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

vs words;
string T,P;
vi b;

void kmpProcess(){
    int m = P.size();
    b.resize(0); b.assign(m+1, 0); b[0]=-1;
    int i=0, j=-1;
    while(i<m){
        while(j>=0 && P[i] != P[j]) j=b[j];
        i++; j++;
        b[i] = j;
    }
}

int kmpSeach(){
    int n=T.size(), m = P.size();
    int i=0,j=0;
    while(i<n){
        while(j>=0 && T[i] != P[j]) j=b[j];
        i++; j++;
    }

    return j;
}

void solve(){
    int w,n; cin>>w>>n;
    words.resize(0);
    for(int i=0; i<n; i++){
        string temp; cin>>temp;
        words.push_back(temp);
    }

    int tot = words[0].size();
    for(int i=0; i<n-1; i++){
        int ni = (i+1)%n;
        T = words[i]; P = words[ni];
        kmpProcess();
        int j = kmpSeach();
        tot += (P.size() - j);
    }

    cout << tot << endl;
}

int main(){
    int tc; cin>>tc;
    for(int i=0; i<tc; i++){
        // cout << "Case #" << i+1 << ": ";
        solve();
    }

    return 0;
}