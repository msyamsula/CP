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
typedef long long ll;
#define MAXLL (1ll<<60)
#define MAXI (1<<30)
ll n;

void solve(){
    if (n==1){
        cout << "0%" << endl;
        return;
    }
    double percent = double(n*100)/4;
    cout << fixed << setprecision(0) << percent << '%' << endl;
}

int main(){
    while(cin>>n){
        if (n<=0) break;
        solve();
    }

    return 0;
}
