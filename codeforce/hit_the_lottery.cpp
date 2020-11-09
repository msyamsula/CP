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
vl dp;
vl coins = {1,5,10,20,100};

void solve(){
    ll choice = 4;
    ll cnt = 0;
    while(n>0){
        while(n<coins[choice]) choice--;
        n -= coins[choice];
        cnt++;
    }
    cout << cnt << endl;    
}

int main(){
    // int tc; cin>>tc;
    // for(int i=0; i<tc; i++){
    //     cout << "Case #" << i+1 << ": ";
    //     solve();
    // }
    cin>>n;
    solve();

    return 0;
}
