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

vs Ts;
string P;
string prefix, suffix;
vs ans;

void searchT(){
    int m = prefix.size();
    int m2 = suffix.size();
    for(string T : Ts){
        int n = T.size();
        if (prefix.size()>n || suffix.size()>n) continue;
        string p = T.substr(0,m);
        string s = T.substr(n-m2,m2);
        // cout << "waw" << s << endl;
        if (p == prefix && s==suffix) ans.push_back(T);
    }
}

void solve(){
    ans.resize(0); Ts.resize(0);
    cin>>P;
    int m = P.size();
    int asti;
    for(int i=0; i<m; i++){
        if (P[i]=='*') asti = i;
    }

    prefix = P.substr(0,asti-0);
    suffix = P.substr(asti+1,m-asti-1);

    // cout << asti+1<< ' ' << m << '&' << suffix << endl;

    int n; cin>>n;
    for(int i=0; i<n; i++){
        string temp; cin>>temp;
        Ts.push_back(temp);
    }
    // cout << prefix << ' ' << suffix << endl;

    searchT();

    for(int i=0; i<ans.size(); i++){
        cout << ans[i] << endl;
    }
}

int main(){
    // int tc; cin>>tc;
    // for(int i=0; i<tc; i++){
    //     cout << "Case #" << i+1 << ": ";
    //     solve();
    // }
    solve();

    return 0;
}