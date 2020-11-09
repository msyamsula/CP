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

string A,B;

void solve(){
    cin>>A>>B;
    string big,small;
    if (A.size()<B.size()){
        big = B;
        small = A;
    } else {
        big = A;
        small = B;
    }
    int n = big.size();
    for(int i=0; i<n ;i++){
        string buf = big.substr(0,i-0);
        buf += big.substr(i+1,n-i-1);
        if (buf == small){
            cout << "Tentu saja bisa!" << endl;
            return;
        }
    }

    cout << "Wah, tidak bisa :(" << endl;
}

int main(){
    solve();
    // int tc; cin>>tc;
    // for(int i=0; i<tc; i++){
    //     cout << "Case #" << i+1 << ": ";
    //     solve();
    // }

    return 0;
}